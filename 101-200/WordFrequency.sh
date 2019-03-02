# Read from the file words.txt and output the word frequency list to stdout.
 awk '{
  for (i = 1; i <= NF; ++i)
   arr[$i] += 1
} END {
  for (i in arr)
  {
     print i, arr[i]
  }
}
' words.txt | sort -nr -k2
