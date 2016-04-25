for i in range(1,100):
	n = i-1 : int
	f = 1
	while n>1:
		if i%n==0:
			f = 0
		n = n-1
	if f:
		print i		
