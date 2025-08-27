#include<stdio.h>                   // New program for Random Seeding Density and Total plate calclation//
#include<math.h>
#include<errno.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
int main()
{
int cell_count;

//cell count=cells counted in four squares

float dis_vol,cell_volume,tot_count_mil,tot_count;

//dis_vol= cell pellet was dissolved in how much vol..
//tot_count=approx.cell count
//tot_count_mil=exact total count in millions

float fc,fd,sm,tm,fm,fcount;
float sd;
float tot_media_vol,media_vol_well,seed_vol_plate,well_vol,cell_dens_well,seed_dens; // For the new program//

int tryp_dil,tot_no_wells;

//tryp_dil= whether trypan blue dilution done or not?
//tot_no_wells= total number of wells present in the entire assay plate

system("clear");
printf(     "\n ****************************************\n");
printf( YEL "\n PROGRAM FOR TOTAL CELL COUNT & SEED_VOL \n" RESET);
printf(     "\n ****************************************\n");
printf( GRN "\n -----READ THE INSTRUCTIONS CAREFULLY---- \n");
printf( RED "\n    1.TYPE ONLY THE VALUES/NUMBERS.\n");
printf( RED "\n    2.DO NOT TYPE THE UNITS!        \n" RESET);
printf (YEL "\n ----------------------------------------- \n" RESET);

printf(     "\n Enter the Volume(mL) the pellet was " );
printf(     "\n dissolved in: " );
scanf( "%f",&dis_vol);  //dis_vol = Dissolving Volume//
printf(     "\n You Entered the volume of: %.2fmL \n",dis_vol);//change on 22-April-25
printf(     "\n Enter the Dilution Factor with Trypan Blue:\n");


printf( GRN "\n (For Example:\n");
printf( GRN "\n Enter:'1' For No Dilution. \n");
printf( GRN "\n Enter:'2' For Dilution with Equal.Vol.Cells with \n");
printf( GRN "\n           equal.vol.Trypan Blue\n");
printf( GRN    "\n Enter the very factor for Other Dilutions)\n\n" RESET);
 
scanf("%d",&tryp_dil);
printf(     "\n You Entered the Trypan Blue"); 
printf(     "\n Dilution Option of: %d \n",tryp_dil);//change on 22-April-25
printf(     "\n Enter the Tot.No.cells counted in " );
printf(     "\n all the four squares: " );
printf( RED   "\n (DO NOT TYPE THE AVERAGE!)\n" RESET);
scanf("%d",&cell_count);  //cell_count = Cells counted in the four squares //
printf(     "\n The No.of Cells from the Four squares"); // Change at 22-April-25 
printf(     "\n you counted is : %d \n",cell_count);
tot_count=((((cell_count/4)*10000)*tryp_dil)*dis_vol);   // Rough calculation of Total cell count in one mL of suspension//
tot_count_mil=(tot_count/1000000); // Exact calculation of total cell count in millions//
printf( CYN "\n The Total cell count \n" RESET);
printf( CYN "\n per 1mL is: %.2f×10^6 Cells (Millions) \n" RESET,tot_count_mil);

int seed_prefer;
printf("\n Which Assay Plate you want to seed in?:\n ");
printf("\n Type '1' to '6' for preferences.\n");
printf("\n '1' FOR 6-WELL PLATE  \n");
printf(GRN "\n     [TOT.VOL:3000.00 uL & SEED.DENS:0.3×10^6 CELLS]\n" RESET);
printf("\n '2' FOR 12-WELL PLATE \n");
printf(GRN "\n     [TOT.VOL:2000.00 uL & SEED.DENS:0.1×10^6 CELLS]\n" RESET);
printf("\n '3' FOR 24-WELL PLATE \n");
printf(GRN "\n     [TOT.VOL:1000.00 uL & SEED.DENS:0.05×10^6 CELLS]\n" RESET);
printf("\n '4' FOR 48-WELL PLATE \n");
printf(GRN "\n     [TOT.VOL:500.00 uL & SEED.DENS:0.03×10^6 CELLS]\n" RESET);
printf("\n '5' FOR 96-WELL PLATE \n");
printf(GRN "\n     [TOT.VOL:200.0 uL & SEED.DENS:0.01×10^6 CELLS]\n" RESET);
printf("\n '6' FOR OTHER PLATE/FLASK SETTINGS \n");
scanf("%d",&seed_prefer);

printf(    "\n The Value of Assay Plate");    // Change by 22-April 
printf(    "\n preference you entered is: %d \n",seed_prefer);

if(seed_prefer==1) //6 well

{

printf(GRN "\n ## You have chosen for 6-Well Assay Plate ##\n" RESET);
well_vol=3000;
seed_dens=0.3;
tot_no_wells=6;

cell_dens_well=(well_vol*seed_dens)/tot_count_mil;

media_vol_well=well_vol-cell_dens_well;
seed_vol_plate=cell_dens_well*tot_no_wells; //tot_no_wells must be included in the derivation portion//
tot_media_vol=media_vol_well*tot_no_wells;

printf (CYN "\n The Final vol.of cells\n"); 
printf (CYN "to be seeded per well is :%.2fuL \n" RESET,cell_dens_well);
printf (CYN "\n The Final vol.of media \n"); 
printf (CYN "per well is :%.2fuL \n" RESET,media_vol_well);
printf (CYN "\n The Final vol.of \n"); 
printf (CYN "cells to be seeded in the\n"); 
printf (CYN "entire plate is  :%.2fuL \n" RESET,seed_vol_plate); 
printf (CYN "\n The Final vol.of media to be \n"); 
printf (CYN "added in the entire plate is :%.2fuL \n" RESET,tot_media_vol); 

printf(YEL "\n***** DERIVATION OF TOTAL CELL COUNT *****\n" RESET);

printf(" \n    %d",cell_count);
printf("\n = ----- × 10,000 × %d × %.2f ",tryp_dil,dis_vol);
printf("\n     4  \n ");

fd=(cell_count)/4;  // fd = First Division //

printf("\n = %.2f × 10,000 × %d × %.2f",fd,tryp_dil,dis_vol);
sm=fd*10000;   // sm = Second Multiplication //

printf("\n = %.2f × %d × %.2f",sm,tryp_dil,dis_vol);

float tryp_multi;
// Introducing a New variable 'tryp_multi' for Trypan Blue dilution//

tryp_multi=(sm*tryp_dil);
printf("\n = %.2f ×%.2f",tryp_multi,dis_vol);

tm=(tryp_multi*dis_vol); //tm= Third Multiplication.

printf("\n = %.2f \n",tm);

fm=tm/1000000; // fm = Fourth Multiplicaiton( in Millions)//
printf("\n = %.2f × 10^6 \n",fm);
printf(CYN "\n The Total Cell Count " RESET);
printf(CYN "\n per 1mL is: %.2f×10^6 Cells (Millions) \n" RESET,fm);

printf(YEL "\n *****DERIVATION OF FINAL SEEDING DENSITY****\n" RESET);

printf("\n V1 × N1 = V2 × N2\n");
printf("\n [Vol.Seed.Dens]×[%.2f×10^6]=[%.2fuL]×[%.2f×10^6] \n",tot_count_mil,well_vol,seed_dens);

printf("\n                     [%.2fuL]×[%.2f×10^6] ",well_vol,seed_dens);   
printf("\n Vol.Seed.Density = ---------------------");
printf("\n                        [%.2f × 10^6] \n",tot_count_mil);  

printf("\n                     [%.2fuL]×[%.2f] ",well_vol,seed_dens);   
printf("\n Vol.Seed.Density = ---------------------");
printf("\n                            [%.2f] \n",tot_count_mil);  

 //Need for a new variable to denote the product of both
 // well_vol and seed_dens, which is prod_well_vol_n_seed_dens//  

float prod_well_vol_n_seed_dens,prod;
prod_well_vol_n_seed_dens=well_vol*seed_dens;
prod=prod_well_vol_n_seed_dens;

printf("\n                            %.2f", prod);  
printf("\n Final.Vol.cells/well = -------------"); 
printf("\n                            [%.2f] \n",tot_count_mil);  

//Need for a new varible to denote the division of prod_well_vol_n_seed_dens by tot_count_mil//
//                 = div_ prod_well_vol_n_seed_dens_n_tot_count_mil//

float div_prod_n_tot_count_mil,div;
div_prod_n_tot_count_mil=prod/tot_count_mil;
div=div_prod_n_tot_count_mil;
printf("\n                      = %.3f\n",div); 
printf(CYN "\n Tot.No.Cells to be seeded per\n"); 
printf(CYN "\n well (V1)is      : %.3f uL \n\n" RESET,div);

float tot_vol_well,tot_vol_plate;//to be pasted in all conditions
tot_vol_well=((cell_dens_well)+(media_vol_well));
tot_vol_plate=seed_vol_plate+tot_media_vol;

// Derivation for Single well and Entire plate calculations
printf(YEL "\n **DERIVATION FOR SINGLE WELL/PLATE VALUES**\n\n" RESET);

printf("\n Tot.Vol.Cells/Single well  :%.3f uL \n",cell_dens_well);
printf("\n                                    (+)  \n");
printf("\n Tot.Vol.Media/Single well  :%.3f uL \n",media_vol_well);
printf(CYN "\n -------------------------------------   \n" RESET);
printf(CYN "\n Tot.Vol.Content/Single well:%.3f uL \n" RESET,tot_vol_well); // float= tot_vol_well & tot_vol_plate
printf(CYN "\n --------------------------------------\n" RESET);

printf("\n Tot.Vol.Cells/Entire Plate  :%.3f uL  \n",seed_vol_plate);
printf("\n                                    (+)  \n");
printf("\n Tot.Vol.Media/Entire Plate  :%.3f uL \n",tot_media_vol);
printf(CYN "\n --------------------------------------------  \n" RESET);
printf(CYN "\n Tot.Vol.Content/Entire Plate:%.3f uL \n" RESET,tot_vol_plate);
printf(CYN "\n --------------------------------------------\n" RESET);

}
else if(seed_prefer==2)//12 well

{
printf(GRN "\n ## You have chosen for 12-Well Assay Plate ##\n" RESET);
well_vol=2000;
seed_dens=0.1;
tot_no_wells=12;

cell_dens_well=(well_vol*seed_dens)/tot_count_mil;

media_vol_well=well_vol-cell_dens_well;
seed_vol_plate=cell_dens_well*tot_no_wells; //tot_no_wells must be included in the derivation portion//
tot_media_vol=media_vol_well*tot_no_wells;

printf (CYN "\n The Final vol.of cells\n"); 
printf (CYN "to be seeded per well is :%.2fuL \n" RESET,cell_dens_well);
printf (CYN "\n The Final vol.of media \n"); 
printf (CYN "per well is :%.2fuL \n" RESET,media_vol_well);
printf (CYN "\n The Final vol.of \n"); 
printf (CYN "cells to be seeded in the\n"); 
printf (CYN "entire plate is  :%.2fuL \n" RESET,seed_vol_plate); 
printf (CYN "\n The final vol.of media to be \n"); 
printf (CYN "added in the entire plate is :%.2fuL \n" RESET,tot_media_vol); 

printf(YEL "\n***** DERIVATION OF TOTAL CELL COUNT *****\n" RESET);


printf(" \n    %d",cell_count);
printf("\n = ----- × 10,000 × %d × %.2f ",tryp_dil,dis_vol);
printf("\n     4  \n ");

fd=(cell_count)/4;  // fd = First Division //

printf("\n = %.2f × 10,000 × %d × %.2f",fd,tryp_dil,dis_vol);
sm=fd*10000;   // sm = Second Multiplication //

printf("\n = %.2f × %d × %.2f",sm,tryp_dil,dis_vol);

float tryp_multi;
// Introducing a New variable 'tryp_multi' for Trypan Blue dilution//

tryp_multi=(sm*tryp_dil);
printf("\n = %.2f ×%.2f",tryp_multi,dis_vol);

tm=(tryp_multi*dis_vol); //tm= Third Multiplication.

printf("\n = %.2f \n",tm);

fm=tm/1000000; // fm = Fourth Multiplicaiton( in Millions)//
printf(CYN "\n The Total Cell Count " RESET);
printf(CYN "\n per 1mL is: %.2f×10^6 Cells (Millions) \n" RESET,fm);

printf(YEL "\n *****DERIVATION OF FINAL SEEDING DENSITY****\n" RESET);

printf("\n V1 × N1 = V2 × N2\n");
printf("\n [Vol.Seed.Dens]×[%.2f×10^6]=[%.2fuL]×[%.2f×10^6] \n",tot_count_mil,well_vol,seed_dens);

printf("\n                     [%.2fuL]×[%.2f×10^6] ",well_vol,seed_dens);   
printf("\n Vol.Seed.Density = ---------------------");
printf("\n                        [%.2f × 10^6] \n",tot_count_mil);  

printf("\n                     [%.2fuL]×[%.2f] ",well_vol,seed_dens);   
printf("\n Vol.Seed.Density = ---------------------");
printf("\n                            [%.2f] \n",tot_count_mil);  

 //Need for a new variable to denote the product of both
 // well_vol and seed_dens, which is prod_well_vol_n_seed_dens//  

float prod_well_vol_n_seed_dens,prod;
prod_well_vol_n_seed_dens=well_vol*seed_dens;
prod=prod_well_vol_n_seed_dens;

printf("\n                            %.2f", prod);  
printf("\n Final.Vol.cells/well = -----------------"); 
printf("\n                            [%.2f] \n",tot_count_mil);  

//Need for a new varible to denote the division of prod_well_vol_n_seed_dens by tot_count_mil//
//                 = div_ prod_well_vol_n_seed_dens_n_tot_count_mil//


float tot_vol_well,tot_vol_plate;
float div_prod_n_tot_count_mil,div;
div_prod_n_tot_count_mil=prod/tot_count_mil;
div=div_prod_n_tot_count_mil;
printf("\n                      = %.3f\n",div);
printf(CYN "\n Tot.No.Cells to be seeded per\n"); 
printf(CYN "\n well (V1)is      : %.3f uL \n\n" RESET,div);

tot_vol_well=((cell_dens_well)+(media_vol_well));
tot_vol_plate=seed_vol_plate+tot_media_vol;


// Derivation for Single well and Entire plate calculations

printf(YEL "\n **DERIVATION FOR SINGLE WELL/PLATE VALUES**\n\n" RESET);

printf("\n Tot.Vol.Cells/Single well   :%.3f uL \n",cell_dens_well);
printf("\n                                    (+)  \n");
printf("\n Tot.Vol.Media/Single well   :%.3f uL \n",media_vol_well);
printf(CYN "\n -------------------------------------   \n" RESET);
printf(CYN "\n Tot.Vol.Content/Single well :%.3f uL \n" RESET,tot_vol_well); // float= tot_vol_well & tot_vol_plate
printf(CYN "\n -------------------------------------   \n" RESET);

printf("\n Tot.Vol.Cells/Entire Plate  :%.3f uL  \n",seed_vol_plate);
printf("\n                                  (+)  \n");
printf("\n Tot.Vol.Media/Entire Plate  :%.3f uL \n",tot_media_vol);
printf(CYN "\n ----------------------------------------   \n" RESET);
printf(CYN "\n Tot.Vol.Content/Entire Plate:%.3f uL \n" RESET,tot_vol_plate);
printf(CYN "\n ----------------------------------------\n " RESET);

}
else if(seed_prefer==3)//24 well

{
printf(GRN "\n ## You have chosen for 24-Well Assay Plate ##\n" RESET);
well_vol=1000;
seed_dens=0.05;
tot_no_wells=24;

cell_dens_well=(well_vol*seed_dens)/tot_count_mil;

media_vol_well=well_vol-cell_dens_well;
seed_vol_plate=cell_dens_well*tot_no_wells; //tot_no_wells must be included in the derivation portion//
tot_media_vol=media_vol_well*tot_no_wells;

printf (CYN "\n The Final vol.of cells\n"); 
printf (CYN "to be seeded per well is :%.2fuL \n" RESET,cell_dens_well);
printf (CYN "\n The Final vol.of media \n"); 
printf (CYN "per well is :%.2fuL \n" RESET,media_vol_well);
printf (CYN "\n The Final vol.of \n"); 
printf (CYN "cells to be seeded in the\n"); 
printf (CYN "entire plate is  :%.2fuL \n" RESET,seed_vol_plate); 
printf (CYN "\n The Final vol.of media to be \n"); 
printf (CYN "added in the entire plate is :%.2fuL \n" RESET,tot_media_vol); 

printf(YEL "\n***** DERIVATION OF TOTAL CELL COUNT *****\n" RESET);


printf(" \n    %d",cell_count);
printf("\n = ----- × 10,000 × %d × %.2f ",tryp_dil,dis_vol);
printf("\n     4  \n ");

fd=(cell_count)/4;  // fd = First Division //

printf("\n = %.2f × 10,000 × %d × %.2f",fd,tryp_dil,dis_vol);
sm=fd*10000;   // sm = Second Multiplication //

printf("\n = %.2f × %d × %.2f",sm,tryp_dil,dis_vol);

float tryp_multi;
// Introducing a New variable 'tryp_multi' for Trypan Blue dilution//

tryp_multi=(sm*tryp_dil);
printf("\n = %.2f ×%.2f",tryp_multi,dis_vol);

tm=(tryp_multi*dis_vol); //tm= Third Multiplication.

printf("\n = %.2f \n",tm);

fm=tm/1000000; // fm = Fourth Multiplicaiton( in Millions)//
printf(CYN "\n The Total Cell Count " RESET);
printf(CYN "\n per 1mL is: %.2f×10^6 Cells (Millions) \n" RESET,fm);

printf(YEL "\n *****DERIVATION OF FINAL SEEDING DENSITY****\n" RESET);

printf("\n V1 × N1 = V2 × N2\n");
printf("\n [Vol.Seed.Dens]×[%.2f×10^6]=[%.2fuL]×[%.2f×10^6] \n",tot_count_mil,well_vol,seed_dens);

printf("\n                     [%.2fuL]×[%.2f×10^6] ",well_vol,seed_dens);   
printf("\n Vol.Seed.Density = ---------------------");
printf("\n                        [%.2f × 10^6] \n",tot_count_mil);  

printf("\n                     [%.2fuL]×[%.2f] ",well_vol,seed_dens);   
printf("\n Vol.Seed.Density = ---------------------");
printf("\n                            [%.2f] \n",tot_count_mil);  

 //Need for a new variable to denote the product of both
 // well_vol and seed_dens, which is prod_well_vol_n_seed_dens//  

float prod_well_vol_n_seed_dens,prod;
prod_well_vol_n_seed_dens=well_vol*seed_dens;
prod=prod_well_vol_n_seed_dens;

printf("\n                            %.2f", prod);  
printf("\n Final.Vol.cells/well = ---------------------"); 
printf("\n                            [%.2f] \n",tot_count_mil);  

//Need for a new varible to denote the division of prod_well_vol_n_seed_dens by tot_count_mil//
//                 = div_ prod_well_vol_n_seed_dens_n_tot_count_mil//

float tot_vol_well,tot_vol_plate;
float div_prod_n_tot_count_mil,div;
div_prod_n_tot_count_mil=prod/tot_count_mil;
div=div_prod_n_tot_count_mil;
printf("\n                      = %.3f\n",div);
printf(CYN "\n Tot.No.Cells to be seeded per\n"); 
printf(CYN "\n well (V1)is      : %.3f uL \n\n" RESET,div);

//to be pasted in all conditions
tot_vol_well=((cell_dens_well)+(media_vol_well));
tot_vol_plate=seed_vol_plate+tot_media_vol;

// Derivation for Single well and Entire plate calculations

printf(YEL "\n **DERIVATION FOR SINGLE WELL/PLATE VALUES**\n\n" RESET);

printf("\n Tot.Vol.Cells/Single well  :%.3f uL \n",cell_dens_well);
printf("\n                                    (+)  \n");
printf("\n Tot.Vol.Media/Single well  :%.3f uL \n",media_vol_well);
printf(CYN "\n ------------------------------------------   \n" RESET);
printf(CYN "\n Tot.Vol.Content/Single well:%.3f uL \n" RESET,tot_vol_well); // float= tot_vol_well & tot_vol_plate
printf(CYN "\n ------------------------------------------   \n" RESET);

printf("\n Tot.Vol.Cells/Entire Plate  :%.3f uL  \n",seed_vol_plate);
printf("\n                                  (+)  \n");
printf("\n Tot.Vol.Media/Entire Plate  :%.3f uL \n",tot_media_vol);
printf(CYN "\n -------------------------------------------  \n" RESET);
printf(CYN "\n Tot.Vol.Content/Entire Plate:%.3f uL \n" RESET,tot_vol_plate);
printf(CYN "\n -------------------------------------------\n" RESET);

}
else if(seed_prefer==4)//48 well

{
printf(GRN "\n ## You have chosen for 48-Well Assay Plate ##\n" RESET);
well_vol=500;
seed_dens=0.03;
tot_no_wells=48;

cell_dens_well=(well_vol*seed_dens)/tot_count_mil;

media_vol_well=well_vol-cell_dens_well;
seed_vol_plate=cell_dens_well*tot_no_wells; //tot_no_wells must be included in the derivation portion//
tot_media_vol=media_vol_well*tot_no_wells;

printf (CYN "\n The Final vol.of cells\n"); 
printf (CYN "to be seeded per well is :%.3fuL \n" RESET,cell_dens_well);
printf (CYN "\n The Final vol.of media \n"); 
printf (CYN "per well is :%.3fuL \n" RESET,media_vol_well);
printf (CYN "\n The Final vol.of \n"); 
printf (CYN "cells to be seeded in the\n"); 
printf (CYN "entire plate is  :%.2fuL \n" RESET,seed_vol_plate); 
printf (CYN "\n The final vol.of media to be \n"); 
printf (CYN "added in the entire plate is :%.2fuL \n" RESET,tot_media_vol); 

printf(YEL "\n***** DERIVATION OF TOTAL CELL COUNT *****\n" RESET);


printf(" \n    %d",cell_count);
printf("\n = ----- × 10,000 × %d × %.2f ",tryp_dil,dis_vol);
printf("\n     4  \n ");

fd=(cell_count)/4;  // fd = First Division //

printf("\n = %.2f × 10,000 × %d × %.2f",fd,tryp_dil,dis_vol);
sm=fd*10000;   // sm = Second Multiplication //

printf("\n = %.2f × %d × %.2f",sm,tryp_dil,dis_vol);

float tryp_multi;
// Introducing a New variable 'tryp_multi' for Trypan Blue dilution//

tryp_multi=(sm*tryp_dil);
printf("\n = %.2f ×%.2f",tryp_multi,dis_vol);

tm=(tryp_multi*dis_vol); //tm= Third Multiplication.

printf("\n = %.2f \n",tm);

fm=tm/1000000; // fm = Fourth Multiplicaiton( in Millions)//
printf(CYN "\n The Total Cell Count " RESET);
printf(CYN "\n per 1mL is: %.2f×10^6 Cells (Millions) \n" RESET,fm);


printf(YEL "\n *****DERIVATION OF FINAL SEEDING DENSITY****\n" RESET);


printf("\n V1 × N1 = V2 × N2\n");
printf("\n [Vol.Seed.Dens]×[%.2f×10^6]=[%.2fuL]×[%.2f×10^6] \n",tot_count_mil,well_vol,seed_dens);

printf("\n                     [%.2fuL]×[%.2f×10^6] ",well_vol,seed_dens);   
printf("\n Vol.Seed.Density = ---------------------");
printf("\n                        [%.2f × 10^6] \n",tot_count_mil);  

printf("\n                     [%.2fuL]×[%.2f] ",well_vol,seed_dens);   
printf("\n Vol.Seed.Density = ---------------------");
printf("\n                            [%.2f] \n",tot_count_mil);  

 //Need for a new variable to denote the product of both
 // well_vol and seed_dens, which is prod_well_vol_n_seed_dens//  
float tot_vol_well,tot_vol_plate;
float div_prod_n_tot_count_mil,div;


float prod_well_vol_n_seed_dens,prod;
prod_well_vol_n_seed_dens=well_vol*seed_dens;
prod=prod_well_vol_n_seed_dens;


printf("\n                            %.2f", prod);  
printf("\n Final.Vol.cells/well = ---------------------"); 
printf("\n                            [%.2f] \n",tot_count_mil);  

//Need for a new varible to denote the division of prod_well_vol_n_seed_dens by tot_count_mil//
//                 = div_ prod_well_vol_n_seed_dens_n_tot_count_mil//

div_prod_n_tot_count_mil=prod/tot_count_mil;
div=div_prod_n_tot_count_mil;
printf("\n                      = %.3f\n",div);
printf(CYN "\n Tot.No.Cells to be seeded per\n"); 
printf(CYN "\n well (V1)is      : %.3f uL \n\n" RESET,div);

//to be pasted in all conditions
tot_vol_well=((cell_dens_well)+(media_vol_well));
tot_vol_plate=seed_vol_plate+tot_media_vol;

// Derivation for Single well and Entire plate calculations

printf(YEL "\n **DERIVATION FOR SINGLE WELL/PLATE VALUES**\n\n" RESET);

printf("\n Tot.Vol.Cells/Single well  :%.3f uL \n",cell_dens_well);
printf("\n                                    (+)  \n");
printf("\n Tot.Vol.Media/Single well  :%.3f uL \n",media_vol_well);
printf(CYN "\n ---------------------------------------\n" RESET);
printf(CYN "\n Tot.Vol.Content/Single well:%.3f uL \n" RESET,tot_vol_well); // float= tot_vol_well & tot_vol_plate
printf(CYN "\n ---------------------------------------   \n" RESET);

printf("\n Tot.Vol.Cells/Entire Plate  :%.3f uL  \n",seed_vol_plate);
printf("\n                                  (+)  \n");
printf("\n Tot.Vol.Media/Entire Plate  :%.3f uL \n",tot_media_vol);
printf(CYN "\n -------------------------------------------   \n" RESET);
printf(CYN "\n Tot.Vol.Content/Entire Plate:%.3f uL \n" RESET,tot_vol_plate);
printf(CYN "\n -------------------------------------------\n" RESET);

return 0;    

}
else if(seed_prefer==5)//96 well

{
printf(GRN "\n ## You have chosen for 96-Well Assay Plate ##\n" RESET);
well_vol=200;
seed_dens=0.01;
tot_no_wells=96;

cell_dens_well=(well_vol*seed_dens)/tot_count_mil;

media_vol_well=well_vol-cell_dens_well;
seed_vol_plate=cell_dens_well*tot_no_wells; //tot_no_wells must be included in the derivation portion//
tot_media_vol=media_vol_well*tot_no_wells;

printf (CYN "\n The Final vol.of cells\n"); 
printf (CYN "to be seeded per well is :%.4fuL \n" RESET,cell_dens_well);
printf (CYN "\n The Final vol.of media \n"); 
printf (CYN "per well is :%.2fuL \n" RESET,media_vol_well);
printf (CYN "\n The Final vol.of \n"); 
printf (CYN "cells to be seeded in the\n"); 
printf (CYN "entire plate is  :%.2fuL \n" RESET,seed_vol_plate); 
printf (CYN "\n The final vol.of media to be \n"); 
printf (CYN "added in the entire plate is :%.2fuL \n" RESET,tot_media_vol); 

printf(YEL "\n***** DERIVATION OF TOTAL CELL COUNT *****\n" RESET);


printf(" \n    %d",cell_count);
printf("\n = ----- × 10,000 × %d × %.2f ",tryp_dil,dis_vol);
printf("\n     4  \n ");

fd=(cell_count)/4;  // fd = First Division //

printf("\n = %.2f × 10,000 × %d × %.2f",fd,tryp_dil,dis_vol);
sm=fd*10000;   // sm = Second Multiplication //

printf("\n = %.2f × %d × %.2f",sm,tryp_dil,dis_vol);

float tryp_multi;
// Introducing a New variable 'tryp_multi' for Trypan Blue dilution//

tryp_multi=(sm*tryp_dil);
printf("\n = %.2f ×%.2f",tryp_multi,dis_vol);

tm=(tryp_multi*dis_vol); //tm= Third Multiplication.

printf("\n = %.2f \n",tm);

fm=tm/1000000; // fm = Fourth Multiplicaiton( in Millions)//
printf(CYN "\n The Total Cell Count " RESET);
printf(CYN "\n per 1mL is: %.2f×10^6 Cells (Millions) \n" RESET,fm);


printf(YEL "\n *****DERIVATION OF FINAL SEEDING DENSITY****\n" RESET);


printf("\n V1 × N1 = V2 × N2\n");
printf("\n [Vol.Seed.Dens]×[%.2f×10^6]=[%.2fuL]×[%.3f×10^6] \n",tot_count_mil,well_vol,seed_dens);

printf("\n                     [%.2fuL]×[%.3f×10^6] ",well_vol,seed_dens);   
printf("\n Vol.Seed.Density = ---------------------");
printf("\n                        [%.2f × 10^6] \n",tot_count_mil);  

printf("\n                     [%.2fuL]×[%.3f] ",well_vol,seed_dens);   
printf("\n Vol.Seed.Density = ---------------------");
printf("\n                            [%.2f] \n",tot_count_mil);  

 //Need for a new variable to denote the product of both
 // well_vol and seed_dens, which is prod_well_vol_n_seed_dens//  

float tot_vol_well,tot_vol_plate;
float div_prod_n_tot_count_mil,div;

float prod_well_vol_n_seed_dens,prod;
prod_well_vol_n_seed_dens=well_vol*seed_dens;
prod=prod_well_vol_n_seed_dens;

printf("\n                            %.2f", prod);  
printf("\n Final.Vol.cells/well = ---------------------"); 
printf("\n                            [%.2f] \n",tot_count_mil);  

//Need for a new varible to denote the division of prod_well_vol_n_seed_dens by tot_count_mil//
//                 = div_ prod_well_vol_n_seed_dens_n_tot_count_mil//

div_prod_n_tot_count_mil=prod/tot_count_mil;
div=div_prod_n_tot_count_mil;
printf("\n                      = %.3f\n",div);
printf(CYN "\n Tot.No.Cells to be seeded per\n"); 
printf(CYN "\n well (V1)is      : %.3f uL \n\n" RESET,div);

//to be pasted in all conditions
tot_vol_well=((cell_dens_well)+(media_vol_well));
tot_vol_plate=seed_vol_plate+tot_media_vol;

// Derivation for Single well and Entire plate calculations

printf(YEL "\n **DERIVATION FOR SINGLE WELL/PLATE VALUES**\n\n" RESET);

printf("\n Tot.Vol.Cells/Single well  :%.3f uL \n",cell_dens_well);
printf("\n                                  (+)  \n");
printf("\n Tot.Vol.Media/Single well  :%.3f uL \n",media_vol_well);
printf(CYN "\n ------------------------------------------ \n" RESET);
printf(CYN "\n Tot.Vol.Content/Single well:%.3f uL \n" RESET,tot_vol_well); // float= tot_vol_well & tot_vol_plate
printf(CYN "\n ----------------------------------------- \n" RESET);

printf("\n Tot.Vol.Cells/Entire Plate  :%.3f uL  \n",seed_vol_plate);
printf("\n                                  (+)  \n");
printf("\n Tot.Vol.Media/Entire Plate  :%.3f uL \n",tot_media_vol);
printf(CYN "\n ---------------------------------------- \n" RESET);
printf(CYN "\n Tot.Vol.Content/Entire Plate:%.3f uL \n" RESET ,tot_vol_plate);
printf(CYN "\n ---------------------------------------\n" RESET);

}
else if(seed_prefer==6)//OTHER SETTINGS

{
printf(GRN "\n # You have chosen Other Plate/Flask Settings #\n" RESET);

printf("\n Enter the Tot.Volume of a Single well\n");
printf(MAG "\n (Example: Type only '10' for 10uL)" RESET);
scanf("%f",&well_vol);
printf("\n Enter the Final Seed.Density of a Single well:\n");
printf(MAG "\n (Example: Type only '0.4' for 0.4 Millions)\n" RESET);
scanf("%f",&seed_dens);
printf("\n Enter the Tot.No.Wells in the Assay Plate:\n");
scanf("%d",&tot_no_wells);

cell_dens_well=(well_vol*seed_dens)/tot_count_mil;
media_vol_well=well_vol-cell_dens_well;
seed_vol_plate=cell_dens_well*tot_no_wells; //tot_no_wells must be included in the derivation portion//
tot_media_vol=media_vol_well*tot_no_wells;

printf (CYN "\n The Final vol.of cells\n"); 
printf (CYN "to be seeded per well is :%.4fuL \n" RESET,cell_dens_well);
printf (CYN "\n The Final vol.of media \n"); 
printf (CYN "per well is :%.2fuL \n" RESET,media_vol_well);
printf (CYN "\n The Final vol.of \n"); 
printf (CYN "cells to be seeded in the\n"); 
printf (CYN "entire plate is  :%.2fuL \n" RESET,seed_vol_plate); 
printf (CYN "\n The Final vol.of media to be \n"); 
printf (CYN "added in the entire plate is :%.2fuL \n" RESET,tot_media_vol); 

printf(YEL "\n***** DERIVATION OF TOTAL CELL COUNT *****\n" RESET);


printf(" \n    %d",cell_count);
printf("\n = ----- × 10,000 × %d × %.2f ",tryp_dil,dis_vol);
printf("\n     4  \n ");

fd=(cell_count)/4;  // fd = First Division //

printf("\n = %.2f × 10,000 × %d × %.2f",fd,tryp_dil,dis_vol);
sm=fd*10000;   // sm = Second Multiplication //

printf("\n = %.2f × %d × %.2f",sm,tryp_dil,dis_vol);

float tryp_multi;
// Introducing a New variable 'tryp_multi' for Trypan Blue dilution//

tryp_multi=(sm*tryp_dil);
printf("\n = %.2f ×%.2f",tryp_multi,dis_vol);

tm=(tryp_multi*dis_vol); //tm= Third Multiplication.

printf("\n = %.2f \n",tm);

fm=tm/1000000; // fm = Fourth Multiplicaiton( in Millions)//
printf(CYN "\n The Total Cell Count " RESET);
printf(CYN "\n per 1mL is: %.2f×10^6 Cells (Millions) \n" RESET,fm);




printf(YEL "\n *****DERIVATION OF FINAL SEEDING DENSITY****\n" RESET);


printf("\n V1 × N1 = V2 × N2\n");
printf("\n [Vol.Seed.Dens]×[%.2f×10^6]=[%.2fuL]×[%.3f×10^6] \n",tot_count_mil,well_vol,seed_dens);

printf("\n                     [%.2fuL]×[%.3f×10^6] ",well_vol,seed_dens);   
printf("\n Vol.Seed.Density = ---------------------");
printf("\n                        [%.2f × 10^6] \n",tot_count_mil);  

printf("\n                     [%.2fuL]×[%.3f] ",well_vol,seed_dens);   
printf("\n Vol.Seed.Density = ---------------------");
printf("\n                            [%.2f] \n",tot_count_mil);  

 //Need for a new variable to denote the product of both
 // well_vol and seed_dens, which is prod_well_vol_n_seed_dens//  

float tot_vol_well,tot_vol_plate;
float div_prod_n_tot_count_mil;

float prod_well_vol_n_seed_dens,prod;
prod_well_vol_n_seed_dens=well_vol*seed_dens;
prod=prod_well_vol_n_seed_dens;

printf("\n                            %.2f", prod);  
printf("\n Final.Vol.cells/well = ---------------------"); 
printf("\n                            [%.2f] \n",tot_count_mil);  

//Need for a new varible to denote the division of prod_well_vol_n_seed_dens by tot_count_mil//
//                 = div_ prod_well_vol_n_seed_dens_n_tot_count_mil//

div_prod_n_tot_count_mil=prod/tot_count_mil;
printf("\n                      = %.4f\n",div_prod_n_tot_count_mil);
printf(CYN "\n Tot.No.Cells to be seeded per\n"); 
printf(    "\n well (V1)is      : %.4f uL \n" RESET,div_prod_n_tot_count_mil);

//to be pasted in all conditions
tot_vol_well=((cell_dens_well)+(media_vol_well));
tot_vol_plate=seed_vol_plate+tot_media_vol;

// Derivation for Single well and Entire plate calculations

printf(YEL "\n **DERIVATION FOR SINGLE WELL/PLATE VALUES**\n\n" RESET);

printf("\n Tot.Vol.Cells/Single well   :%.3f uL \n",cell_dens_well);
printf("\n                                    (+)  \n");
printf("\n Tot.Vol.Media/Single well   :%.3f uL \n",media_vol_well);
printf(CYN "\n ------------------------------------------ \n" RESET);
printf(CYN "\n Tot.Vol.Content/Single well :%.3f uL \n" RESET,tot_vol_well); // float= tot_vol_well & tot_vol_plate
printf(CYN "\n -------------------------------------------   \n" RESET);

printf("\n Tot.Vol.Cells/Entire Plate  :%.3f uL  \n",seed_vol_plate);
printf("\n                                  (+)  \n");
printf("\n Tot.Vol.Media/Entire Plate  :%.3f uL \n",tot_media_vol);
printf(CYN "\n ------------------------------------------- \n" RESET);
printf(CYN "\n Tot.Vol.Content/Entire Plate:%.3f uL \n" RESET,tot_vol_plate);
printf(CYN "\n ---------------------------------------------   \n" RESET);

}
else
{
printf (RED "\n --ENTER ONLY A NUMBER FROM '1' TO '6'. START AGAIN!- \n" RESET);
}
return 0;
}
