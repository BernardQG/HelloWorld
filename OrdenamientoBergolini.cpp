	int mayor = 10000, auxm;
	//parchesin, ordenamiento bergolini
	for (int i = 0; i < c; i++)
	{
		mayor = 10000;
		for (int j = 0; j <c; j++)
		{
			if (vector[j] < mayor && vector[j] != 0){
				mayor = vector[j];
				auxm = j;
			}

		}
		cout << vector[auxm] << " ";
		vector[auxm] = 0;
	}
	system("pause");
