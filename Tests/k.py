import os,sys
terminal = sys.stdout
sys.stdout = open('file', 'w')
files = os.popen('find $directory -type f -name "*.cpp"').read().split('\n')
print files
output = ""
for f in files:
	os.popen("g++ -Wall -g -pthread "+f+" -lgtest_main  -lgtest -lpthread")
	out = os.popen("./a.out").read()
	output +="\n\n\n\n"
	output +=out
	output +="\n\n\n\n"

sys.stdout = terminal

print output
