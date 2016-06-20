# Easy269
BASIC Formatting (taken from: https://www.reddit.com/r/dailyprogrammer/comments/4lpygb/20160530_challenge_269_easy_basic_formatting/)

#Description:
It's the year 2095. In an interesting turn of events, it was decided 50 years ago that BASIC is by far the universally best language. You work for a company by the name of SpaceCorp, who has recently merged with a much smaller company MixCo. While SpaceCorp has rigorous formatting guidelines, exactly 4 space per level of indentation, MixCo developers seem to format however they please at the moment. Your job is to bring MixCo's development projects up to standards.

#Input Description:
You'll be given a number N, representing the number of lines of BASIC code. Following that will be a line containing the text to use for indentation, which will be ···· for the purposes of visibility. Finally, there will be N lines of pseudocode mixing indentation types (space and tab, represented by · and » for visibility) that need to be reindented.

Blocks are denoted by IF and ENDIF, as well as FOR and NEXT.

#Output Description:
You should output the BASIC indented by SpaceCorp guidelines.

#Challenge Input:
    12
    ····
    VAR I
    ·FOR I=1 TO 31
    »»»»IF !(I MOD 3) THEN
    ··PRINT "FIZZ"
    ··»»ENDIF
    »»»»····IF !(I MOD 5) THEN
    »»»»··PRINT "BUZZ"
    ··»»»»»»ENDIF
    »»»»IF (I MOD 3) && (I MOD 5) THEN
    ······PRINT "FIZZBUZZ"
    ··»»ENDIF
    »»»»·NEXT
  
  


