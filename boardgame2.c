#include <stdio.h>
#include <Windows.h>
#include <conio.h>
int board[80][80];
void gotoxy(int x, int y) {
	 HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); 
	  COORD cursorCoord;
	 cursorCoord.X = y;
	 cursorCoord.Y = x;
	 SetConsoleCursorPosition(consoleHandle, cursorCoord);
}
int lineColumnsnumbering(int TotalRows,int TotalColumn ){
	///////////////////////////////////////////////line numbering.
   	int  Row, Column ,name_lines=65;
    for(Row = 0; Row <= TotalRows; Row++){  
		if((Row+2)%4==0){
				board[Row][TotalColumn+1]=(Row+2)/4;			
		}
		//Naming between lines.
		else if(Row!=0 && Row%4==0 && Row<TotalRows){
			board[Row][TotalColumn+1]= name_lines;    
			 name_lines++;	 		
		}else{
				board[Row][TotalColumn+1]=0; //put space.
		}
	}
	/////////////////////////////////////////////Columns numbering.	
	
	name_lines=65;
	for(Column = 1; Column <= TotalColumn; Column++){
			// numbering of Columns (1-9).
			if((Column+2)%5==0 && Column<47){
				board[TotalRows+1][Column]=(Column+2)/5;	
			// numbering of Columns more than 9.
			}else if(Column>=47 && (Column-7)%4==0 && Column<TotalColumn-2 ){
				if(Column<63){ // 10-13
						board[TotalRows+1][Column]=(Column-7)/4;
				}else if(Column<TotalColumn-4){ //14-15
							board[TotalRows+1][Column]=(Column-7)/4;
					}else{
							//put space.
							board[TotalRows+1][Column]=0;
					}			
			}
			//Naming between Columns (1-10).
			else if (Column %5 ==0 && Column<47){
					board[TotalRows+1][Column]=name_lines;
					name_lines++;	
			}
			else {
					//put space.
					board[TotalRows+1][Column]=0;
			}	
	}		
}
int boardgame(int bordDimensions ,int TotalRows,int TotalColumn ){
	int  Row, Column;
	int  existence = 0; //existence checks if we have reached the end of the row.
	int Player_House = 3, SpaceBetween_Row=4, SpaceBetween_Column_oddRow=5, SpaceBetween_Column_evenRow=5, sw=1;

	///////////////////////////////////////////////////////////////////////////////////// //Building board
	for(Row = 1; Row < TotalRows ; Row++){
        for(Column = 2; Column < TotalColumn ; Column++){
            if(Row % 2 == 1){ 
               //Checking the space between houses in Column for odd row .
               if(Column == SpaceBetween_Column_oddRow){
                  SpaceBetween_Column_oddRow += 5; //THe space between the Column is 5.
                  existence++;
                  
                  if(existence < bordDimensions  ){ // if existence < bordDimensions we need space after house   
				  	if(board[Row][Column]!=100 )   {
                     board[Row][Column] = 0; //if the coordinate is related to the space between the Column, put 2 space.
                     board[Row][Column+1] = 0;
                      
               	   }
               	    Column++;
                     sw = 0;
                  }
               }
               if(sw == 1 ) board[Row][Column] = 1; //Building walls of houses
               sw = 1;
            }
            else{
            
            	//Checking the space between houses in rows .
                if(Row == SpaceBetween_Row &&board[Row][Column]!=100 ){
                   board[Row][Column] = 0;  //if the coordinate is related to the space between the rows, put space.
                   if(Column == TotalColumn-1) SpaceBetween_Row += 4; //THe space between the rows is 4.
                 }
                else{
                	//checking player's house.
                	
                    if(Column == Player_House ){
                       Player_House += 5; //The distance between player houses is 5 .
                       if(board[Row][Column]!=100 && board[Row][Column]!=200){
                       board[Row][Column] = 0; //if the coordinate is related to the player's house , put space. 
                         }
                       sw = 0;
                    }
                    //Checking the space between houses in Column for even row .
                    if(Column == SpaceBetween_Column_evenRow ){
                       if(board[Row][Column]!=100 ){
                       board[Row][Column] = 0; //if the coordinate is related to the space between the Column for even row, put 2 space.
                       board[Row][Column+1] = 0;
                   }
                       Column++;
                       SpaceBetween_Column_evenRow += 5; //THe space between the Column is 5.
                    }
                    else{
                    	//Building walls of houses.
                        if(sw == 1 && board[Row][Column]!=100  ){
                        	board[Row][Column] = 1; 
						} 
						
                        sw = 1;
                    }
                   
                }
           }
        }
        Player_House = 3;
        SpaceBetween_Column_oddRow = 5;
        existence = 0;
        SpaceBetween_Column_evenRow = 5;
    }
    lineColumnsnumbering(TotalRows,TotalColumn );
   	/////////////////////////////////////////////////////////////// making a frame around the board
	for(Column = 1; Column < TotalColumn -1 ; Column++){
		board[0][Column]=2;  // for row=0 && row=last
		board[TotalRows][Column]=2;
	}
	for(Row = 1; Row < TotalRows ; Row++){
		board[Row][1]=3; //for Column=1 && Column=last
		board[Row][TotalColumn]=3;
	}
	///////////////////////////////////////////////////////////////////
    
}
void printboardgame(int bordDimensions){
	int  Row, Column ,name_lines=65,situation;	;
	const int TotalRows=4*bordDimensions;
	const int TotalColumn=5*bordDimensions;

	boardgame(bordDimensions,TotalRows,TotalColumn);
	
	for(Row = 0; Row <= TotalRows+1; Row++){
	    for(Column = 1; Column <= TotalColumn; Column++){
	    	//////////print 4 corners of the frame
			if(Row==0 && Column==1){
					printf("%c",201);
			}
			if(Row==0 && Column==TotalColumn-1){
					printf("%c",187);
			}
			if(Row==TotalRows && Column==TotalColumn-1){
					printf("%c",188);
			}
			if(Row==TotalRows && Column==1){
					printf("%c",200);
			}
			
			////////////// print houses
	        if(board[Row][Column] == 0 && Row!=TotalRows+1){
	        	printf(" ");
			} 
	        else if(board[Row][Column] == 1 && Row!=TotalRows+1) {
	        	printf(".");
			}
			////////// print main frame
			else if(board[Row][Column]==2 && Column<TotalColumn-1 && Row!=TotalRows+1)	{	
				
						printf("%c",205);
			}
		    else if(board[Row][Column]==3 && Row!=TotalRows+1)	{	
						printf("%c",215);
			}
			///////////print line nums.	
	        if(Column==TotalColumn && board[Row][Column+1]!=0 ){    
						if(board[Row][Column+1]>64){
								printf("%c",board[Row][Column+1]);
						}else{
							printf("%d",board[Row][Column+1]);
						}								
			}
			/////////print Column nums.
			if(Row==TotalRows+1){		
					if(board[Row][Column]!=0 && Column<TotalColumn){
						if(board[Row][Column]>64){ 
								printf("%c",board[Row][Column]);
						}else{
								printf("%d",board[Row][Column]);
								}	
					}else{
						printf(" ");
					}			
				}	
	      /////////////
	   	if(board[Row][Column]==100){
	   				printf("%c",178);
		   }
	    }
	    printf("\n");
	}
	////////////////////print the letters j and later to name the Columns.
	name_lines=74;	
	situation=49;
	for(Row=bordDimensions ; bordDimensions>10 ; bordDimensions--){
		gotoxy(TotalRows+2,situation);
		printf("%c",name_lines);
		situation+=5;
		name_lines++;	
	}
	////////////////////////////
}
int main(){
	int bordDimensions;
	scanf("%d",&bordDimensions);
    		board[4][5]=100;
	board[4][6]=100;
	board[4][4]=100;
	board[4][3]=100;
	board[4][5]=100;
	board[4][7]=100;
	board[4][8]=100;
	board[4][2]=100;
	board[4][9]=100; 

	printboardgame(bordDimensions);
}

