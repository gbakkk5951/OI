for i in `ls *.c`; do
	echo "Compiling $i..."
	obj=${i/.c/}
	gcc $i -o $obj
done
