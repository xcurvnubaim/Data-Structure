
file_path=$1
file_prog=$2
direc="$file_path/.."

g++ $file_prog -o $direc/a.out

for entry in ${file_path}/input/*; do
    echo $entry
    input_file=$entry
    $direc/a.out < $input_file > $direc/out.txt
    output_file=${input_file//input/output}
    diff -w $direc/out.txt $output_file
done
