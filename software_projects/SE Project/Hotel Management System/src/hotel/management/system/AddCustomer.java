package hotel.management.system;
import javax.swing.*;
import java.awt.*;
import java.sql.*; 
import java.util.Date;
import java.awt.event.*;

public class AddCustomer  extends JFrame implements ActionListener
{
    JComboBox comboid,gendercombo;
    JTextField tfnumber,tfname,tfcountry,tfdeposit;
    Choice croom;
    JLabel checkintime;
    JButton add,cancle;
    AddCustomer()
    {
        getContentPane().setBackground(Color.WHITE);
        setLayout(null);
        
        JLabel text=new JLabel("NEW CUSTOMER FORM");
        text.setBounds(100,20,300,30);
        text.setFont(new Font("Raleway",Font.PLAIN,20));
        add(text);
        
        JLabel lblid= new JLabel("ID");
        lblid.setBounds(35,80,100,20);
        lblid.setFont(new Font("Raleway",Font.PLAIN,20));
        add(lblid);
        
        String options[]={"NID","Passpord","Birth Certificated"};
        comboid=new JComboBox(options);
        comboid.setBounds(200,80,150,25);
        comboid.setBackground(Color.WHITE);
        add(comboid);
        
        JLabel lblnumber= new JLabel("Number");
        lblnumber.setBounds(35,120,100,20);
        lblnumber.setFont(new Font("Raleway",Font.PLAIN,20));
        add(lblnumber);
        
        tfnumber=new JTextField();
        tfnumber.setBounds(200,120,150,20);
        add(tfnumber);
        
        JLabel lblname= new JLabel("Name");
        lblname.setBounds(35,160,100,20);
        lblname.setFont(new Font("Raleway",Font.PLAIN,20));
        add(lblname);
        
        tfname=new JTextField();
        tfname.setBounds(200,160,150,20);
        add(tfname);
        
        JLabel lblclean = new JLabel("Gender");
        lblclean.setFont(new Font("Raleway",Font.PLAIN,20));
        lblclean.setBounds(35,190,120,30);
        add(lblclean);
        
        String cleanOptions[] = {"Male", "Female"};
        gendercombo = new JComboBox(cleanOptions);
        gendercombo.setBounds(200,190,150,25);
        gendercombo.setBackground(Color.WHITE);
        add(gendercombo);
        
        JLabel lblcountry= new JLabel("Country");
        lblcountry.setBounds(35,240,100,20);
        lblcountry.setFont(new Font("Raleway",Font.PLAIN,20));
        add(lblcountry);
        
        tfcountry=new JTextField();
        tfcountry.setBounds(200,240,150,20);
        add(tfcountry);
        
        JLabel lblroom= new JLabel("Room Number");
        lblroom.setBounds(35,280,150,20);
        lblroom.setFont(new Font("Raleway",Font.PLAIN,20));
        add(lblroom);
        
        croom=new Choice();
        
        try
        {
            Conn conn=new Conn();
            String query="select * from room where availability='Available'";
            ResultSet rs=conn.s.executeQuery(query);
            while(rs.next())
            {
                croom.add(rs.getString("roomnumber"));
            }
        }
        catch(Exception e)
        {
             e.printStackTrace();
        }
        croom.setBounds(200,280,150,25);
        add(croom);
        
        JLabel lbltime= new JLabel("Checkin Time");
        lbltime.setBounds(35,320,150,20);
        lbltime.setFont(new Font("Raleway",Font.PLAIN,20));
        add(lbltime);
        
        Date date= new Date();
        
        checkintime= new JLabel(""+date);
        checkintime.setBounds(200,320,150,25);
        checkintime.setFont(new Font("Raleway",Font.PLAIN,16));
        add(checkintime);
        
        JLabel lbldeposit= new JLabel("Deposit");
        lbldeposit.setBounds(35,360,100,20);
        lbldeposit.setFont(new Font("Raleway",Font.PLAIN,20));
        add(lbldeposit);
        
        tfdeposit=new JTextField();
        tfdeposit.setBounds(200,360,150,20);
        add(tfdeposit);
        
        add = new JButton("Add");
        add.setForeground(Color.WHITE);
        add.setBackground(Color.BLACK);
        add.setBounds(50,410,120,30);
        add.addActionListener(this);
        add(add);
        
        cancle = new JButton("Cancle");
        cancle.setForeground(Color.WHITE);
        cancle.setBackground(Color.BLACK);
        cancle.setBounds(200,410,120,30);
        cancle.addActionListener(this);
        add(cancle);
        
        ImageIcon i1 = new ImageIcon(ClassLoader.getSystemResource("icons/Capture.jpg"));
        Image i2 = i1.getImage().getScaledInstance(300,400,Image.SCALE_DEFAULT);
        ImageIcon i3 = new ImageIcon(i2);
        JLabel image= new JLabel(i3);
        image.setBounds(400,50,300,400);
        add(image);
        
        setBounds(350,200,800,550);
        setVisible(true);
    }
    public void actionPerformed(ActionEvent ae)
    { 
        if(ae.getSource() == add)
        {
           String id = (String)comboid.getSelectedItem();
           String number = tfnumber.getText();
           String name = tfname.getText();
           String gender = (String) gendercombo.getSelectedItem(); 
           
           String country= tfcountry.getText();
           String room= croom.getSelectedItem(); 
           String time= checkintime.getText();
           String deposit= tfdeposit.getText();
           
           if (id.equals("")||number.equals("")||name.equals("")||gender.equals("")||country.equals("")||room.equals("")||time.equals("")||deposit.equals(""))
           {
               JOptionPane.showMessageDialog(null, "Please Fill The All Field");
               return;
           }
           try
           {
              String query="insert into customer values('"+id+"','"+number+"','"+name+"','"+gender+"','"+country+"','"+room+"','"+time+"','"+deposit+"')"; 
              String  query2="update room set availability='Occupied' where roomnumber='"+room+"'";
              
              Conn conn =new Conn();
              conn.s.executeUpdate(query);
              conn.s.executeUpdate(query2);
              
              JOptionPane.showMessageDialog(null, "New Customer Added Successfully");
              
              setVisible(false);
              new Reception();
           }
           catch (Exception e) 
           {
             e.printStackTrace();
           }

        }
       
        else
        {
            setVisible(false);
            new Reception();
        }
        
    }
    public static void main(String[] args) 
    {
       new AddCustomer();
    }
    
}
