# Read from the file file.txt and print its transposed content to stdout.

#awk '{
#for (i = 1; i <= NF; ++i)
#    arr[i, FNR] = $i;
#num_col = NF;
#num_row = FNR;
#} END {
#for (i = 1; i <= num_col; ++i)
#{
#    for (j = 1; j <= num_row; ++j)
#    {
#        printf("%s", arr[i, j]);
#        if (j == num_row)
#            printf("\n");
#        else
#            printf(" ");
#    }
#}
#}' file.txt

awk '{
for (i = 1; i <= NF; ++i)
    if (FNR == 1)
        arr[i] = $i
    else
        arr[i] = arr[i]" "$i
} END {
for (i in arr)
    print arr[i]
}' file.txt
