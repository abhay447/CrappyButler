counter=1
for f in *.pcm;do
mv $f $counter.pcm;
((counter++));
echo $f;
done
