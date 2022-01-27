int *getNumberOfDigits(int n)
{
	int count = 0, int firstDigit = 0;
	while (n != 0)
	{
		firstDigit = n % 10;
		n /= 10;
		count++;
	}

	int arr[2];
	arr[0] = count;
	arr[1] = firstDigit;

	return arr;
}

bool shouldInclude(int i)
{
	int *arr = getNumberOfDigits(i);

	if (arr[1] + arr[0] > 10)
		return false;

	int prevDigit = i % 10, currDigit = i % 10;
	while (i != 0)
	{
		currDigit = i % 10;
		if (currDigit - prevDigit <= 0)
			return true;

		prevDigit = currDigit;
		i /= 10;
	}
	return false;
}

int updateI(int i, count)
{
	int add = pow(10, count - 1);
	i += add;
	return i;
}

int sequencialDigit(i)
{
	int *arr = getNumberOfDigits(i);
	int res = arr[1];
	arr[0]--;

	while (arr[0]--)
	{
		arr[1]++;
		res += res * 10 + arr[1];
	}

	return res;
}

int *sequentialDigits(int low, int high, int *returnSize)
{

	int *count = getNumberOfDigits(low);

	int i = updateI(i, count[0]);
	if (shouldInclude(low))
		i *= count[1];
	else
		i *= (count[1] + 1);

	while (i <= high)
	{
		if (shouldInclude(i))
		{
			arr.push_back(sequencialDigit(i))
		}
		i = update(i, count[0])
	}
}

/*
low = 100
high = 300

low currDigit - prevDigit >1   (Example low = 124)
	function does not run

i = 892
i <= high (finalCheck)

*/