
package hotel.management.system;


import java.awt.*;
import javax.swing.*;
//import java.awt.event.*;
//import java.sql.*;

public class Login extends JFrame /*implements ActionListener*/{
    
    //JLabel l1,l2;
    //JTextField t1;
    //JPasswordField t2;
    //JButton b1,b2;

    Login(){
         
        getContentPane().setBackground(Color.WHITE);
       // super("Login");

        setLayout(null);
        
        JLabel user = new JLabel("Username");
        user.setBounds(40,20,100,30);
        add(user);
        
        JTextField username =new JTextField();
        username.setBounds(150,20,150,30);
        add(username);
        
        JLabel pass = new JLabel("Password");
        pass.setBounds(40,70,100,30);
        add(pass);
        
        JTextField Password =new JTextField();
        Password.setBounds(150,70,150,30);
        add(Password);
       
        JButton login = new JButton("Login");
        login.setBounds(40,150,120,30);
        login.setBackground(Color.BLACK);
        login.setForeground(Color.WHITE);
        add(login);
        
        JButton cancel = new JButton("Cancel");
        cancel.setBounds(180,150,120,30);
        cancel.setBackground(Color.BLACK);
        cancel.setForeground(Color.WHITE);
        add(cancel);
        
        ImageIcon i1 = new ImageIcon(ClassLoader.getSystemResource("icons/second.jpg"));
        Image i2 = i1.getImage().getScaledInstance(200,200,Image.SCALE_DEFAULT);
        ImageIcon i3 =  new ImageIcon(i2);
        JLabel image = new JLabel(i3);
        image.setBounds(350,10,150,150);
        add(image);
        
        setBounds(500,200,600,300);
        setVisible(true);

        
    }

   /* public void actionPerformed(ActionEvent ae){
        if(ae.getSource()==b1){
        //try{
           // conn c1 = new conn();
            String u = t1.getText();
            String v = t2.getText();
            
            String q = "select * from login where username='"+u+"' and password='"+v+"'";
            
          //  ResultSet rs = c1.s.executeQuery(q); 
            //if(rs.next()){ 
               // new Dashboard().setVisible(true);
                setVisible(false);
           // }else{
                JOptionPane.showMessageDialog(null, "Invalid login");
                setVisible(false);
            }
       // }catch(Exception e){
            //e.printStackTrace();
        }*/
       // }else if(ae.getSource()==b2){
        //    System.exit(0);
        //}
   // }
    public static void main(String[] arg){
        new Login();
    }
}
