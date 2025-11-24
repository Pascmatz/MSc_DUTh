#include <stdio.h>
#include <string.h>

int main()

{

	char seq [ 100000 ];
	int len, i, j ;
	int valid_cr;

	printf( "Give the sequences: \n" );


	while ( scanf( "%s", seq) ==  1)

	{
		len = strlen( seq );
		valid_cr = 0;

		// First check length, we need at least 6 nucleotides
		if ( len < 6 )
			{
				printf("Invalid data! Sequence is too short.\n");
				continue;
			}


		// Check for start codon
		for ( i = 0 ; i <= len-3 ; i++ )

			{
				if ( seq [ i ] == 'A' && seq [ i+1 ] == 'T' && seq [ i+2 ] == 'G')
					{
						// Check for stop codon in the same reading frame
						for ( j = i+3 ; j <= len-3 ; j += 3 )

							{
								if (( seq [ j ] == 'T' && seq [ j+1 ] == 'A' && seq [ j+2 ] == 'A') ||
								( seq [ j ] == 'T' && seq [ j+1 ] == 'A' && seq [ j+2 ] == 'G') ||
								( seq [ j ] == 'T' && seq [ j+1 ] == 'G' && seq [ j+2 ] == 'A'))
									{
										printf( "Start codon: %d, End codon: %d, Length: %d.\n", i+1, j+1, (j-i) + 3 );
										valid_cr = 1;
										i = j+1; // Keep reading after the first stop codon for another coding region
										break;
									}

							}

					}

			}

		if (!valid_cr)
			{
				printf("Invalid coding region.\n");
			}

	}

	return 0;

}
