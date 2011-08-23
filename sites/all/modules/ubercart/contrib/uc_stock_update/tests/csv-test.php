<?php
// $Id: csv-test.php 4480 2010-05-30 01:52:22Z david $

// Simple "manual" tests for CSV handling
// Assumes you have the command line utilities
//  printf
//  base64
// Run with...
//  php csv-test.php | cat -ev     
require_once (dirname(__FILE__) . '/../ReadCSV.inc');

function test($cmd, $expected) {
  static $count =0;
  $count++;

  $reader = new ReadCSV(popen($cmd, 'rb'), ',');
  while (($row = $reader->get_row()) !== NULL) {
    $x=array_shift($expected);
    if ($x !== $row)
      return "Test $count FAILED: expected ". implode(', ', $x) ." found ". implode(', ', $row);
  }
  if (count($expected) > 0)
    return "Test $count FAILED: terminated before ". implode(', ', array_shift($expected));

  return "Test $count OK";
}


function test_str($str, $expected) {
  // test with LF line endings
  $b64=base64_encode(str_replace('%', "\n", $str));
  echo test("printf %s $b64 | base64 --decode", $expected), "\n";
  // test with CRLF line endings
  $b64=base64_encode(str_replace('%', "\r\n", $str));
  echo test("printf %s $b64 | base64 --decode", $expected), "\n";
}


// A '%' in the strings below represnts an end-of-line sequence
test_str('', array());
test_str('%',  array(array('')));
test_str('1%', array(array('1')));

test_str('1,2', array(array('1','2')));
test_str('1,2%', array(array('1','2')));
test_str('1,2%3,4', array(array('1','2'), array('3','4')));
test_str('1,2%3,4%', array(array('1','2'), array('3','4')));

// Test quote handling
test_str('"1,2"', array(array('1,2')));
test_str('"1,2"%', array(array('1,2')));
test_str('"1"",2"%', array(array('1",2')));
test_str('"1"",2"%"3"""%',
	  array(array('1",2'), array('3"')));
test_str('"1"",2"%"3"""',
	  array(array('1",2'), array('3"')));
test_str('"1'."\r".'"",2"%"3"""%',
	  array(array("1\r\",2"), array('3"')));
test_str('"1"",'."\n".'2"%"3""", 4',
	 array(array("1\",\n2"), array('3"',' 4')));

