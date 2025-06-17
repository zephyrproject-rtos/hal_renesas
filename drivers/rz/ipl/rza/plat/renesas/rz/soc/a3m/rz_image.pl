#!/usr/bin/perl -w
# Copyright (c) 2021, Renesas Electronics Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

use strict;
use bigint;
use Digest::SHA;

sub padding256 {
    my ($f, $size, $fourth) = @_;

    for(my $i=1;$i<4;$i++) {
        $f->print(pack('C', 0));
    }
    $f->print(pack('C', $fourth));
    for(my $i=5;$i<57;$i++) {
        $f->print(pack('C', 0));
    }
    $f->print(pack('C',($size & (0b111 << 29)) >> 29));
    for(my $i=58;$i<61;$i++) {
        $f->print(pack('C', 0));
    }
    $f->print(pack('C',($size & (0x1F << 0)) << 3));
    $f->print(pack('C',($size & (0xFF << 5)) >> 5));
    $f->print(pack('C',($size & (0xFF << 13)) >> 13));
    $f->print(pack('C',($size & (0xFF << 21)) >> 21));
    for(my $i=65;$i<257;$i++) {
        $f->print(pack('C', 0));
    }
}

my $size_limit = 0x1D000;

die("Not enough parameter\n") if ($#ARGV < 0);

# Open input file
my $name = shift(@ARGV);
my $outname;
if ($#ARGV < 0) {
	$outname = "rz_" . $name;
}
else {
	$outname = shift(@ARGV);
}
my $tmpname = $outname.".tmp";
open(my $origin, '<', $name) or die("Can not open input file");
binmode $origin;

# Obtaining size ($st[7])
my @st = stat($origin);

# Check appended size
my $size = ($st[7] + 255) & "0xffffffffffffff00";
my $msg;
if ($size != $st[7]) {$msg = "Appended size";} else {$msg="Size";}
die("$msg too big ($size > $size_limit)") if ($size > $size_limit);

open(my $tmp, '>', $tmpname) or die("Can not open temporary file");
binmode $tmp;

# WritePadding
my $buf;
read($origin, $buf, $st[7]);
$tmp->print($buf);
#print "size:$size st:$st[7]\n";
if ($size != $st[7]) {
    $tmp->print(pack('C', 0x80));
    for(my $i=($st[7] + 1);$i<$size;$i++) {
		$tmp->print(pack('C', 0));
    }
    padding256($tmp, $st[7], 0);
} else {
    padding256($tmp, $st[7], 0x80);
}
close($tmp);
open($tmp, '<', $tmpname) or die("Can not open temporary file");
# Sha256
my $sha = Digest::SHA->new(256);
$sha->addfile($tmpname);
my $digest = $sha->digest();

seek($origin, 0,0);
$size += 256;

# Create bin file
open(my $out, '>', $outname) or die("Can not open output file");
binmode $out;
# Write header
$out->print(pack('L', $size));
for(my $i = 1; $i < 4; $i++) {
    $out->print(pack('L', 0xffffffff));
}
$out->print($digest);
for(my $i = 12; $i < 112; $i++) {
	$out->print(pack('L', 0xffffffff));
}
$out->print(pack('L', 0xffff0000));
$out->print(pack('L', 0x000800ff));
$out->print(pack('L', 0x00fff700));
$out->print(pack('L', 0xf700f708));
$out->print(pack('L', 0xffffffff));
$out->print(pack('L', 0xffffffff));
$out->print(pack('L', 0xffffffff));
$out->print(pack('L', 0xffffffff));
$out->print(pack('L', 0xffffffff));
$out->print(pack('L', 0xffffffff));
$out->print(pack('L', 0xffffffff));
$out->print(pack('L', 0xffffffff));
$out->print(pack('L', 0xffffffff));
$out->print(pack('L', 0xffffffff));
$out->print(pack('L', 0xffffffff));
$out->print(pack('L', 0xaa55ffff));

# Append original data to temporary file
read($tmp, $buf, $size);
$out->print($buf);
$out->flush;

close($tmp);
#unlink($tmpname);
# close
close $out;
close $origin;
