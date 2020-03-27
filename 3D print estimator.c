# include<stdio.h>
# include<math.h>

//Material Prices (Dollars Per Hour)
const int PLAperhour = 6;
const int ABSperhour = 10;
const int PETGperhour = 8;
const int Flexperhour = 12;

//Scaling Parameters
const float timescalepower = 1.1;
const int scalingimpact = 2; 

//User enterable data
int timeHours;
int timeMinutes;
int filament;
int overhangrisk;
int support;
int warprisk;
int rush;

// variables
float time;
float standardprice;
float adjustedprice;

float scalingfactor;
int timescaling;



int main(void){
	
	while(1){ //Keep running program infinitely until closed, needs to be changed
	
//DATA ENTRY
	printf("Welcome to P3DP quoting \n");
	printf("To get a quote you need to enter some data \n\n");
	
	printf("Enter print time:  "); 
	scanf("%d,%d",&timeHours,&timeMinutes);
	printf("Enter filament, 1=PLA, 2=ABS, 3=PETG, 4=Flex:  ");
	scanf("%d",&filament);
	printf("Enter support material 0 to 3:  ");
	scanf("%d",&support);
	printf("Enter overhang risk 0 to 3:  ");
	scanf("%d",&overhangrisk);
	printf("Enter warp risk 0 to 3:  ");
	scanf("%d",&warprisk);
	printf("Enter requested lead time in days:  ");
	scanf("%d",&rush);
	
	
//PROCESSING
	time = (timeHours+((float)timeMinutes/60)); //Gives time in hours
	
	if(filament==1){
		standardprice=pow(time,timescalepower)*PLAperhour;
	}
	else if(filament==2){
		standardprice=pow(time,timescalepower)*ABSperhour;
	}
	else if(filament==3){
		standardprice=pow(time,timescalepower)*PETGperhour;
	}
	else if(filament==4){
		standardprice=pow(time,timescalepower)*Flexperhour;
	}
	else{
		printf("filament choice error!!");
	}
	
	scalingfactor= ((float)support/3)+((-1+(float)overhangrisk)/3)+((-1+(float)warprisk)/3)+((3-(float)rush)/3);
	
	adjustedprice = standardprice*(1+(scalingfactor/scalingimpact));
	
	printf("Price = %f \n\n",adjustedprice);
	
	
}
	return 0;
	
	
}
