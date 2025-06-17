#!/usr/bin/perl -w
# Copyright (c) 2021, Renesas Electronics Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

use strict;
use bigint;
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
open(my $origin, '<', $name) or die("Can not open input file");
binmode $origin;

# Obtaining size ($st[7])
my @st = stat($origin);

# Check appended size
my $size = ($st[7] + 3) & "0xfffffffffffffffc";
my $msg;
if ($size != $st[7]) {$msg = "Appended size";} else {$msg="Size";}
die("$msg too big ($size > $size_limit)") if ($size > $size_limit);

# Create temporary file
open(my $out, '>', $outname) or die("Can not open output file");
binmode $out;

# Write header
$out->print(pack('L', $size));
for(my $i = 1; $i < 112; $i++) {
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
my $buf;
read($origin, $buf, $st[7]);
$out->print($buf);
if($st[7] < $size) {
	warn "Not aligned. Append " . ($size-$st[7]) . " zero(s)";
	# Append zero
	for(;$st[7] < $size; $size--) {
		$out->print(pack('C', 0));
	}
}
$out->flush;

# close
close $out;
close $origin;
