int main(void)
{
	int y=3;
	int &x = y;
	
	int* address_y=&y;
	int* &ref_y = address_y;
	
	int array[3] ={1,2,3};
		
	int* address_array= array;
	int* &ref_address_array = address_array;
	//int* &ref = array;//error
}
