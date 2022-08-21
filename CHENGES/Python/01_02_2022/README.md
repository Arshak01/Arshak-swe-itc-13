## Project-name
	 Sourted by <key><part><part> using ASCII

## Project-description
	We have a line consisting of 3 parts: <key> <part> <part>. <key> has a clear structure, first letter + number (w1, er3, 		t456 ...) <part> has the following structures: letters only (ert), numbers only (45),letter + number (w23), but not number + 		letter (4 w5 or 7y).
	Enter n number of rows, sort by:
	- First the letter lines are placed, then the numeric ones (a digital line is the line whose <part> Ts consist only of 			numbers: (w1 456 7) - numeric (ds3 23 w3) - letter);
		"Heart the letter lines" as follows:
	- First of all, you need to look at the letter of the <key>, sort by ASCII
	If the length of the letter is repeated, look at the length of the <key>
	If the length is the same, sort by the numeric part of <key> (in digits)
	If <key> s are exactly the same as <part>:
	"First of all, you should look at the content of the letter: if there is a letter in one part and not in the other, the one 		containing the letter rises" (we3 f45 fr4> we3 12 f45)
	Then the length of <part>
	֊Then sort according to the letter part of ASCII
	֊After the new digital part (in digits)
	ՍSort digital lines as follows:
	First look at the numeric part of <key> (in digits)
	֊After the <key> length
	֊Follow <key> according to ASCII
	If <key> s are exactly the same as <part>:
	:First you need to look at the length of <part>
	

## Code source 
	-

## Description
For running project, need to open terminal,write down on terminal : `python3 project-name.py`  and after that command run project.

## Usage:
From build dir, write on terminal
	1.`ctrl+alt t`
	2.`python3 projectName.py`

## Contents
Thanks for reading :)
