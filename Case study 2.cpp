#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *file;

//Function displaymenu
void displayMenu(){
	printf("What do you want to do?\n");
	printf("1. Display Data\n");
	printf("2. Search Data\n");
	printf("3. Sort Data\n");
	printf("4. Export Data\n");
	printf("5. Exit\n");
	
}

//Struct untuk menyimpan data
struct datas{
	char location[100];
	char city[100];
	char price[100];
	char rooms[100];
	char bathrooms[100];
	char carparks[100];
	char type[100];
	char furnish[100];
};

//function untuk header
void displayHeader(){
	char header[8][100];
	fscanf(file,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",header[0],header[1],header[2],header[3],header[4],header[5],header[6],header[7]);
	printf("%-29s %-23s %-23s %-23s %-23s %-23s %-23s %-23s",header[0],header[1],header[2],header[3],header[4],header[5],header[6],header[7]);
}

void Choice1(struct datas data, int rows) {
	puts("");
	displayHeader();
    for (int i = 0; i < rows; i++) {
        if (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", data.location, data.city, data.price, data.rooms, data.bathrooms, data.carparks, data.type, data.furnish) != EOF) {
            printf("%-30s %-23s %-23s %-23s %-23s %-23s %-23s %-23s", data.location, data.city, data.price, data.rooms, data.bathrooms, data.carparks, data.type, data.furnish);
        }
    }
    puts("");
    puts("");
    rewind(file);
}

void Choice2(char cols[100], char query[100], struct datas data) {
	
    char currentLine[1000];
    int foundData = 0; 
    while (fgets(currentLine, sizeof(currentLine), file) != NULL) {
        sscanf(currentLine, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", data.location, data.city, data.price, data.rooms, data.bathrooms, data.carparks, data.type, data.furnish);
        if (strcmp(cols, "Location") == 0 && strcmp(data.location, query) == 0) {
            foundData = 1;
            break;
        } else if (strcmp(cols, "City") == 0 && strcmp(data.city, query) == 0) {          
            foundData = 1;
            break;
        } else if (strcmp(cols, "Price") == 0 && strcmp(data.price, query) == 0) {           
            foundData = 1;
           	break;
        } else if (strcmp(cols, "Rooms") == 0 && strcmp(data.rooms, query) == 0) {    
            foundData = 1;
         	break;
        } else if (strcmp(cols, "Bathrooms") == 0 && strcmp(data.bathrooms, query) == 0) {        
            foundData = 1;
          	break;
        } else if (strcmp(cols, "Carparks") == 0 && strcmp(data.carparks, query) == 0) {
            foundData = 1;
            break;
        } else if (strcmp(cols, "Type") == 0 && strcmp(data.type, query) == 0) {          
            foundData = 1;
            break;
        } else if (strcmp(cols, "Furnish") == 0 && strcmp(data.furnish, query) == 0) {
            foundData = 1;
            break;
        }
    }
    
    rewind(file);
    
    if(foundData){
    	puts("");
    	displayHeader();
    	puts("");
		
	    while (fgets(currentLine, sizeof(currentLine), file) != NULL) {
	        sscanf(currentLine, " %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", data.location, data.city, data.price, data.rooms, data.bathrooms, data.carparks, data.type, data.furnish);
	        if (strcmp(cols, "Location") == 0 && strcmp(data.location, query) == 0) {
				printf("%-29s %-23s %-23s %-23s %-23s %-23s %-23s %-23s\n", data.location, data.city, data.price, data.rooms, data.bathrooms, data.carparks, data.type, data.furnish);          
	        } else if (strcmp(cols, "City") == 0 && strcmp(data.city, query) == 0) {
	            printf("%-29s %-23s %-23s %-23s %-23s %-23s %-23s %-23s\n", data.location, data.city, data.price, data.rooms, data.bathrooms, data.carparks, data.type, data.furnish);         
	        } else if (strcmp(cols, "Price") == 0 && strcmp(data.price, query) == 0) {
	            printf("%-29s %-23s %-23s %-23s %-23s %-23s %-23s %-23s\n", data.location, data.city, data.price, data.rooms, data.bathrooms, data.carparks, data.type, data.furnish);   
	        } else if (strcmp(cols, "Rooms") == 0 && strcmp(data.rooms, query) == 0) {
	            printf("%-29s %-23s %-23s %-23s %-23s %-23s %-23s %-23s\n", data.location, data.city, data.price, data.rooms, data.bathrooms, data.carparks, data.type, data.furnish);         
	        } else if (strcmp(cols, "Bathrooms") == 0 && strcmp(data.bathrooms, query) == 0) {
	            printf("%-29s %-23s %-23s %-23s %-23s %-23s %-23s %-23s\n", data.location, data.city, data.price, data.rooms, data.bathrooms, data.carparks, data.type, data.furnish);          
	        } else if (strcmp(cols, "Carparks") == 0 && strcmp(data.carparks, query) == 0) {
	            printf("%-29s %-23s %-23s %-23s %-23s %-23s %-23s %-23s\n", data.location, data.city, data.price, data.rooms, data.bathrooms, data.carparks, data.type, data.furnish);        
	        } else if (strcmp(cols, "Type") == 0 && strcmp(data.type, query) == 0) {
	            printf("%-29s %-23s %-23s %-23s %-23s %-23s %-23s %-23s\n", data.location, data.city, data.price, data.rooms, data.bathrooms, data.carparks, data.type, data.furnish);
	        } else if (strcmp(cols, "Furnish") == 0 && strcmp(data.furnish, query) == 0) {
	            printf("%-29s %-23s %-23s %-23s %-23s %-23s %-23s %-23s\n", data.location, data.city, data.price, data.rooms, data.bathrooms, data.carparks, data.type, data.furnish);
	        }
	    }    	
	}else{
		printf("Data not found!\n");	
	}
	
	rewind(file);
    puts("");
}

//QSORT FOR CHOICE 3
int ascLocation (const void *x, const void *y){
	const struct datas *a = (const struct datas *)x;
	const struct datas *b = (const struct datas *)y;
	return strcmp(a->location,b->location);
}
int dscLocation (const void *x, const void *y){
	const struct datas *a = (const struct datas *)x;
	const struct datas *b = (const struct datas *)y;
	return strcmp(b->location,a->location);
}

int ascCity (const void *x, const void *y){
	const struct datas *a = (const struct datas *)x;
	const struct datas *b = (const struct datas *)y;
	return strcmp(a->city,b->city);
}
int dscCity (const void *x, const void *y){
	const struct datas *a = (const struct datas *)x;
	const struct datas *b = (const struct datas *)y;
	return strcmp(b->city,a->city);
}

int ascPrice (const void *x, const void *y){
	const struct datas *a = (const struct datas *)x;
	const struct datas *b = (const struct datas *)y;
	return strcmp(a->price,b->price);
}
int dscPrice (const void *x, const void *y){
	const struct datas *a = (const struct datas *)x;
	const struct datas *b = (const struct datas *)y;
	return strcmp(b->price,a->price);
}

int ascRooms (const void *x, const void *y){
	const struct datas *a = (const struct datas *)x;
	const struct datas *b = (const struct datas *)y;
	return strcmp(a->rooms,b->rooms);
}
int dscRooms (const void *x, const void *y){
	const struct datas *a = (const struct datas *)x;
	const struct datas *b = (const struct datas *)y;
	return strcmp(b->rooms,a->rooms);
}

int ascBathrooms (const void *x, const void *y){
	const struct datas *a = (const struct datas *)x;
	const struct datas *b = (const struct datas *)y;
	return strcmp(a->bathrooms,b->bathrooms);
}
int dscBathrooms (const void *x, const void *y){
	const struct datas *a = (const struct datas *)x;
	const struct datas *b = (const struct datas *)y;
	return strcmp(b->bathrooms,a->bathrooms);
}

int ascCarparks (const void *x, const void *y){
	const struct datas *a = (const struct datas *)x;
	const struct datas *b = (const struct datas *)y;
	return strcmp(a->carparks,b->carparks);
}
int dscCarparks (const void *x, const void *y){
	const struct datas *a = (const struct datas *)x;
	const struct datas *b = (const struct datas *)y;
	return strcmp(b->carparks,a->carparks);
}

int ascType (const void *x, const void *y){
	const struct datas *a = (const struct datas *)x;
	const struct datas *b = (const struct datas *)y;
	return strcmp(a->type,b->type);
}
int dscType (const void *x, const void *y){
	const struct datas *a = (const struct datas *)x;
	const struct datas *b = (const struct datas *)y;
	return strcmp(b->type,a->type);
}

int ascFurnish (const void *x, const void *y){
	const struct datas *a = (const struct datas *)x;
	const struct datas *b = (const struct datas *)y;
	return strcmp(a->furnish,b->furnish);
}
int dscFurnish (const void *x, const void *y){
	const struct datas *a = (const struct datas *)x;
	const struct datas *b = (const struct datas *)y;
	return strcmp(b->furnish,a->furnish);
}
//QSORT FOR CHOICE 3

void Choice3(char cols[100], char sort[100]) {
    struct datas data[2450]; // declare jumlah data struct yang akan dipakai
    int count = 0; // Menghitung jumlah data
    
        if (strcmp(cols, "Location") == 0){ // COLUMN LOCATION
        	//HEADER
			displayHeader();
			puts("");
			//HEADER
			
		    while (count < 2450 && fscanf(file, " %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", data[count].location, data[count].city, data[count].price, data[count].rooms, data[count].bathrooms, data[count].carparks, data[count].type, data[count].furnish) != EOF) {
		        count++;
		    }
		    
		    if(strcmp(sort,"asc") == 0){
		    	qsort(data,count,sizeof(struct datas),ascLocation);
			}else if(strcmp(sort,"dsc") == 0){
				qsort(data,count,sizeof(struct datas),dscLocation);
			}
			
		    for (int i = 0; i < count; i++) {
		        printf("%-29s %-23s %-23s %-23s %-23s %-23s %-23s %-23s\n", data[i].location, data[i].city, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
		    }
		    
        }else if (strcmp(cols, "City") == 0){ // COLUMN CITY     
			//HEADER
			displayHeader();
			puts("");
			//HEADER
			
		    while (count < 2450 && fscanf(file, " %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", data[count].location, data[count].city, data[count].price, data[count].rooms, data[count].bathrooms, data[count].carparks, data[count].type, data[count].furnish) != EOF) {
		        count++;
		    }
		    
		    if(strcmp(sort,"asc") == 0){
		    	qsort(data,count,sizeof(struct datas),ascCity);
			}else if(strcmp(sort,"dsc") == 0){
				qsort(data,count,sizeof(struct datas),dscCity);
			}
			
		    for (int i = 0; i < count; i++) {
		        printf("%-30s %-23s %-23s %-23s %-23s %-23s %-23s %-23s\n", data[i].location, data[i].city, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
		    }	
					  
        } else if (strcmp(cols, "Price") == 0){ // COLUMN PRICE        
			//HEADER
			displayHeader();
			puts(""); 
			//HEADER
			
		    while (count < 2450 && fscanf(file, " %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", data[count].location, data[count].city, data[count].price, data[count].rooms, data[count].bathrooms, data[count].carparks, data[count].type, data[count].furnish) != EOF) {
		        count++;
			}
			
		    if(strcmp(sort,"asc") == 0){
		    	qsort(data,count,sizeof(struct datas),ascPrice);
			}else if(strcmp(sort,"dsc") == 0){
				qsort(data,count,sizeof(struct datas),dscPrice);
			}
			
		    for (int i = 0; i < count; i++) {
		        printf("%-30s %-23s %-23s %-23s %-23s %-23s %-23s %-23s\n", data[i].location, data[i].city, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
		    }
		    
        } else if (strcmp(cols, "Rooms") == 0){ // COLUMN ROOMS
			//HEADER
			displayHeader();
			puts("");
			//HEADER
			
		    while (count < 2450 && fscanf(file, " %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", data[count].location, data[count].city, data[count].price, data[count].rooms, data[count].bathrooms, data[count].carparks, data[count].type, data[count].furnish) != EOF) {
		        count++;
		    }
		    
		    if(strcmp(sort,"asc") == 0){
		    	qsort(data,count,sizeof(struct datas),ascRooms);
			}else if(strcmp(sort,"dsc") == 0){
				qsort(data,count,sizeof(struct datas),dscRooms);
			}
			
		    for (int i = 0; i < count; i++) {
		        printf("%-30s %-23s %-23s %-23s %-23s %-23s %-23s %-23s\n", data[i].location, data[i].city, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
		    }		
        } else if (strcmp(cols, "Bathrooms") == 0){ // COLUMN BATHROOMS    
			//HEADER
			displayHeader();
			puts("");
			//HEADER
			
		    while (count < 2450 && fscanf(file, " %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", data[count].location, data[count].city, data[count].price, data[count].rooms, data[count].bathrooms, data[count].carparks, data[count].type, data[count].furnish) != EOF) {
		        count++;
		    }
		    
		    if(strcmp(sort,"asc") == 0){
		    	qsort(data,count,sizeof(struct datas),ascBathrooms);
			}else if(strcmp(sort,"dsc") == 0){
				qsort(data,count,sizeof(struct datas),dscBathrooms);
			}
			
		    for (int i = 0; i < count; i++) {
		        printf("%-30s %-23s %-23s %-23s %-23s %-23s %-23s %-23s\n", data[i].location, data[i].city, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
		    }
					   
        } else if (strcmp(cols, "Carparks") == 0){ // COLUMN CARPARKS
			//HEADER			
			displayHeader();
			puts("");
			//HEADER
			
		    while (count < 2450 && fscanf(file, " %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", data[count].location, data[count].city, data[count].price, data[count].rooms, data[count].bathrooms, data[count].carparks, data[count].type, data[count].furnish) != EOF) {
		        count++;
			}
			
		    if(strcmp(sort,"asc") == 0){
		    	qsort(data,count,sizeof(struct datas),ascCarparks);
			}else if(strcmp(sort,"dsc") == 0){
				qsort(data,count,sizeof(struct datas),dscCarparks);
			}
			
		    for (int i = 0; i < count; i++) {
		        printf("%-30s %-23s %-23s %-23s %-23s %-23s %-23s %-23s\n", data[i].location, data[i].city, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
		    }	
        } else if (strcmp(cols, "Type") == 0){ // COLUMN TYPE     
			//HEADER
			displayHeader();
			puts("");
			//HEADER
			
		    while (count < 2450 && fscanf(file, " %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", data[count].location, data[count].city, data[count].price, data[count].rooms, data[count].bathrooms, data[count].carparks, data[count].type, data[count].furnish) != EOF) {
		        count++;
		    }
		    
		    if(strcmp(sort,"asc") == 0){
		    	qsort(data,count,sizeof(struct datas),ascType);
			}else if(strcmp(sort,"dsc") == 0){
				qsort(data,count,sizeof(struct datas),dscType);
			}
			
		    for (int i = 0; i < count; i++) {
		        printf("%-30s %-23s %-23s %-23s %-23s %-23s %-23s %-23s\n", data[i].location, data[i].city, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
		    }	
				         
        } else if (strcmp(cols, "Furnish") == 0){ // COLUMN FURNISH
        	//HEADER
			displayHeader();
			puts("");
			//HEADER
			
		    while (count < 2450 && fscanf(file, " %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", data[count].location, data[count].city, data[count].price, data[count].rooms, data[count].bathrooms, data[count].carparks, data[count].type, data[count].furnish) != EOF) {
		        count++;
		    }
		    
		    if(strcmp(sort,"asc") == 0){
		    	qsort(data,count,sizeof(struct datas),ascFurnish);
			}else if(strcmp(sort,"dsc") == 0){
				qsort(data,count,sizeof(struct datas),dscFurnish);
			}
			
		    for (int i = 0; i < count; i++) {
		        printf("%-30s %-23s %-23s %-23s %-23s %-23s %-23s %-23s\n", data[i].location, data[i].city, data[i].price, data[i].rooms, data[i].bathrooms, data[i].carparks, data[i].type, data[i].furnish);
		    }	
					   
    	}
	    rewind(file);
	    puts("");  
}

//CHOICE 4 FOR EXPORTING DATA
void Choice4(char filename[100], struct datas data) {
    FILE *exportfile = fopen(strcat(filename, ".csv"), "w");
	
	//File validation
    if (exportfile == NULL) {
        printf("Failed to create the file.\n");
        return;
    }
    
    //HEADER
	char header[8][100];
	fscanf(file,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",header[0],header[1],header[2],header[3],header[4],header[5],header[6],header[7]);
	fprintf(exportfile,"%-30s %-23s %-23s %-23s %-23s %-23s %-23s %-23s",header[0],header[1],header[2],header[3],header[4],header[5],header[6],header[7]);
	//HEADER
	
	//Scanning from file and printing data from file to exported file
    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", data.location, data.city, data.price, data.rooms, data.bathrooms, data.carparks, data.type, data.furnish) != EOF) {
        fprintf(exportfile, "%-31s %-23s %-23s %-23s %-23s %-23s %-23s %-23s", data.location, data.city, data.price, data.rooms, data.bathrooms, data.carparks, data.type, data.furnish);
    }

    fclose(exportfile);
    printf("Data successfully written to file %s!\n\n", filename);
}


//MAIN PROGRAM
int main(){
	file = fopen("file.csv","r");
	if(file == NULL){
		printf("failed to open.\n");
		return 1;
	}
	
	struct datas data;

	int n = 0;
	
	while(n!=5){
		displayMenu();
		printf("Your choice: ");
		scanf("%d",&n);
		
		switch(n){
			case 1:
				int rows;
				printf("Number of rows: ");
				scanf("%d",&rows);
				Choice1(data,rows);
				break;
			case 2:
				char cols[100];
				char query[100];
				printf("Choose column: ");
				scanf("%s",cols);
				printf("What do you want to find? ");
				scanf("%s",query);
				Choice2(cols,query,data);
				break;
			case 3:
				char sort[100];
				printf("Choose column: ");
				scanf("%s",cols);
				printf("Sort ascending or descending? ");
				scanf("%s",sort);	
				Choice3(cols,sort);
				break;
			case 4:
				char filename[100];
				printf("File name: ");
				scanf("%s",filename);
				Choice4(filename,data);		
				break;
			case 5:
				printf("Exiting program...\n");
				return 1;
			default:
				printf("Invalid option.\n\n");
				break;
		}
	}
	return 0;
}
