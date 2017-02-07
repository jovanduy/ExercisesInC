void make_num_huge(int num) {
	num = 100;
}

int main() {
	int num = 5;
	make_num_huge(num);
	printf("%s\n", num);
	return 0;
}
