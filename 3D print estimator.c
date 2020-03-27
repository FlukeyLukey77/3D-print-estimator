# include<stdio.h>
# include<math.h>

//Material Prices (Dollars Per Hour)
const int plaHourly = 6;
const int absHourly = 10;
const int petHourly = 8;
const int flexHourly = 12;

//Scaling Parameters
const float timeScalePower = 1.1; //Power of time scaling
const int scalingImpact = 2; 

//User enterable data
int timeHours;
int timeMinutes;
int filament;
int overhangRank;
int supportRank;
int warpRank;
int rushRank;

// variables
float actualTime;
float standardPrice;
float adjustedPrice;

float scalingFactor;
int timeScaling;

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
	scanf("%d",&supportRank);
	printf("Enter overhang risk 0 to 3:  ");
	scanf("%d",&overhangRank);
	printf("Enter warp risk 0 to 3:  ");
	scanf("%d",&warpRank);
	printf("Enter requested lead time in days:  ");
	scanf("%d",&rushRank);
	
	
//PROCESSING
	actualTime = (timeHours+((float)timeMinutes/60)); //Gives time in hours
		
	scaledTime = pow(time, timeScalePower);
	
	switch(Filament)
	{
		case 1:
			standardPrice = scaledTime * plaHourly;
		break;
		case 2:
			standardPrice = scaledTime * absHourly;
		break;
		case 3:
			standardPrice = scaledTime * petHourly;
		break;
		case 4:
			standardPrice = scaledTime * flexHourly;
		break;
		default:
			printf("Error, Invalid choice of filament");
	}
		
	scalingFactor= ((float)supportRank/3)+((-1+(float)overhangRank)/3)+((-1+(float)warpRank)/3)+((3-(float)rushRank)/3);
	
	adjustedPrice = standardPrice*(1+(scalingFactor/scalingImpact));
	
	printf("Price = %f \n\n",adjustedPrice);
	
	
}
	return 0;
	
	
}
