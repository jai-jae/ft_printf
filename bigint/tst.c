int main()
{
	unsigned short int a;
	unsigned char b;
	a = 0xABCD;
	b = (char)(a>>8);
	printf("%x", b);
	return (0);
}
