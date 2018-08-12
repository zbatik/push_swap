BIN=../push_swap
CHK=../checker
echo Identity
$BIN 42
$BIN 0 1 2 3
$BIN 0 1 2 3 4 5 6 7 8 9
echo Simple
ARG="2 1 0"; $BIN $ARG | $CHK $ARG
$BIN 2 1 0 | wc -l
ARG="1 5 2 4 3"; $BIN $ARG | $CHK $ARG
RND=$(ruby -e "puts (0..4).to_a.shuffle.join(' ')") 
$BIN $RND | wc -l
