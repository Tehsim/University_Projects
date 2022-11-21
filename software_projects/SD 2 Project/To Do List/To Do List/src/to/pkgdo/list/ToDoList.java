


package to.pkgdo.list;

import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;

public class ToDoList {

    
    
    static String fileName = "D:\\data\\todolist.txt"; 
    public static void main(String[] args)throws IOException {
        
        
        
       // Scanner inpu = new Scanner(System.in);
        System.out.println("\n\n ======Software Development Project=======\n");    
        System.out.println("\n              TO Do List  \n               Project      \n ");    
        System.out.println("\n==========================================");    
        System.out.println(" ");    
        System.out.println(" Made By: Tehsim Fariha,Sadiya Afrin Priya,Nujhat Tabassum\n");
        System.out.println(" Instructor: Mrs. Atia Binti Aziz \n");
        System.out.println(" Institution: International Islamic University Chittagong \n");
        System.out.println("\n----------------------------------------------\n----------------------------------------------\n");         
        
        
        
        
       // TODO code application logic here
       
        int menuItem = -1;
        while(menuItem !=0){
            menuItem = menu();
            switch(menuItem) {
                case 1:
                    showList();
                    break;
                case 2:
                    addItem();
                    break;
                case 3:
                    removeItem();
                    break; 
                case 0:  
                    break; 
                default:
                    System.out.println("Don't recognize input.");    
                    
            }
        }
       
  
    }
    
    static int menu(){
        int choice;
        Scanner input = new Scanner(System.in);
        System.out.println("\nMain Menu\n");    
        System.out.println("0. Exit the program ");    
        System.out.println("1. Dispaly to-do-list");    
        System.out.println("2. Add item to to-do-list");    
        System.out.println("3. Remove item from to-do list");    
        System.out.println();                   
        System.out.println("Enter a choice : ");                     
        choice = input.nextInt();
        return choice;
          
    
    
    }
    
    

    static void showList() {
        System.out.println("\nTo-do List\n");
        try {
            Scanner inFile = new Scanner(new FileReader(fileName));
            String line;
            int number = 1;
            while (inFile.hasNextLine()) {
                line = inFile.nextLine();
                System.out.print(number + " ");
                System.out.println(line);
                ++number;
            }
            System.out.println();
            inFile.close();
        }
        catch (IOException ioe) {
            System.out.println("Can't acess file.");
        }
    }
    
    
    static  void  addItem(){
        System.out.println("\nAdd Item\n");
        try {
            Scanner input = new Scanner(System.in);
            PrintWriter outFile = new PrintWriter(new FileWriter(fileName, true));
            System.out.print("Enter an item: ");
            String item = input.nextLine();
            outFile.println(item);
            outFile.close();
        }
        catch (IOException ioe) {
            System.out.println("Can't acess file.");
        }
    }
    
     
    static  void   removeItem(){
    
        int choice;
        showList();
        Scanner input=new Scanner(System.in);
        System.out.print("Which item do you want to remove?");
        choice=input.nextInt();
        ArrayList<String> items= new ArrayList<String>();
        int number=1;
        try{
            
            Scanner inFile=new Scanner(new FileReader(fileName));
            String item;
            while (inFile.hasNextLine()){
                item = inFile.nextLine();
                if (number !=choice)
                    items.add(item);
                ++number;
            }
            PrintWriter outFile = new PrintWriter(new FileWriter(fileName));
            for (int i=0; i < items.size(); ++i)
                outFile.println (items.get(i));
            outFile.close();
            
        }
        catch(IOException ioe){
                System.out.println("cannot access file.");
        }
      
    }

    
   }
    
    
    
    
    
