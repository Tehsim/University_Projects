package hotel.management.system;
import javax.swing.*;
import java.awt.*;
import java.sql.*; 
import java.awt.event.*;//action r jono

public class AddEmployee extends JFrame implements ActionListener
{
    JTextField tfname,tfemail,tfphone,tfage,tfsalary,tfnid;
    JComboBox gendercombo;
    JButton add,cancel;
    JComboBox cbjob;
    AddEmployee()
    {
       setLayout(null);
       
       JLabel lblname= new JLabel("NAME");
       lblname.setBounds(60, 30, 120, 30);
       lblname.setFont(new Font("Tahoma",Font.PLAIN,17));
       add(lblname);
       
       tfname=new JTextField();
       tfname.setBounds(200, 80, 150, 30);
       add(tfname);
       
       JLabel lblage= new JLabel("AGE");
       lblage.setBounds(60, 80, 120, 30);
       lblage.setFont(new Font("Tahoma",Font.PLAIN,17));
       add(lblage);
       
       tfage=new JTextField();
       tfage.setBounds(200, 30, 150, 30);
       add(tfage);
       
       JLabel lblgender= new JLabel("GENDER");
       lblgender.setBounds(60, 130, 120, 30);
       lblgender.setFont(new Font("Tahoma",Font.PLAIN,17));
       add(lblgender);
     
        String cleanOptions[] = {"Male", "Female"};
        gendercombo = new JComboBox(cleanOptions);
        gendercombo.setBounds(200,130,150,30);
        gendercombo.setBackground(Color.WHITE);
        add(gendercombo);
       
       JLabel lbljob= new JLabel("JOB");
       lbljob.setBounds(60, 180, 120, 30);
       lbljob.setFont(new Font("Tahoma",Font.PLAIN,17));
       add(lbljob);
       
       String str[]={"Front Desk Clerks","Porters","House keeping","Kitchen Staff","Room Service","Chefs","Waiter/Waitress","Manager","Accountant"};
       cbjob = new JComboBox(str);//as array of string
       cbjob.setBounds(200,180,150,30);
       cbjob.setBackground(Color.WHITE);
       add(cbjob);
       
       JLabel lblsalary= new JLabel("SALARY");
       lblsalary.setBounds(60, 230, 120, 30);
       lblsalary.setFont(new Font("Tahoma",Font.PLAIN,17));
       add(lblsalary);
       
       tfsalary=new JTextField();
       tfsalary.setBounds(200, 230, 150, 30);
       add(tfsalary);
       
       JLabel lblphone= new JLabel("PHONE");
       lblphone.setBounds(60, 280, 120, 30);
       lblphone.setFont(new Font("Tahoma",Font.PLAIN,17));
       add(lblphone);
       
       tfphone=new JTextField();
       tfphone.setBounds(200, 280, 150, 30);
       add(tfphone);
       
       JLabel lblemail= new JLabel("EMAIL");
       lblemail.setBounds(60, 330, 120, 30);
       lblemail.setFont(new Font("Tahoma",Font.PLAIN,17));
       add(lblemail);
       
       tfemail=new JTextField();
       tfemail.setBounds(200, 330, 150, 30);
       add(tfemail);
       
       JLabel lblnid= new JLabel("NID");
       lblnid.setBounds(60, 380, 120, 30);
       lblnid.setFont(new Font("Tahoma",Font.PLAIN,17));
       add(lblnid);
       
       tfnid =new JTextField();
       tfnid.setBounds(200, 380, 150, 30);
       add(tfnid);
       
    
       
        add = new JButton("Add");
        add.setForeground(Color.WHITE);
        add.setBackground(Color.BLACK);
        add.setBounds(50,430,150,30);
        add.addActionListener(this);
        add(add);
        
        cancel = new JButton("Cancel");
        cancel.setForeground(Color.WHITE);
        cancel.setBackground(Color.BLACK);
        cancel.setBounds(300,430,150,30);
        cancel.addActionListener(this);
        add(cancel);
       
       ImageIcon i1= new ImageIcon(ClassLoader.getSystemResource("icons/tenth.jpg"));
       Image i2=i1.getImage().getScaledInstance(450, 450, Image.SCALE_DEFAULT);
       ImageIcon i3= new ImageIcon(i2);
       JLabel image=new JLabel(i3);
       image.setBounds(380,60,450,370);
       add(image);
       
       getContentPane().setBackground(Color.WHITE);
       setBounds(350,200,850,540);
       setVisible(true);
    }
    public void actionPerformed(ActionEvent ae)
    { 
        if(ae.getSource()==add)
        {
               
       String n = tfname.getText();
       String age = tfage.getText();
       String salary = tfsalary.getText();
       String phone = tfphone.getText();
       String email = tfemail.getText();
       String nid = tfnid.getText();
       String job= (String)cbjob.getSelectedItem();
       String gender = (String) gendercombo.getSelectedItem();
       
       if (n.equals("")||phone.equals("")||age.equals("")||salary.equals("")||email.equals("")||nid.equals("")||job.equals("")||gender.equals(""))
       {
           JOptionPane.showMessageDialog(null, "Please Fill The All Field");
           return;
       }
      // String job= (String)cbjob.getSelectedItem();//get obj k return kore but amr string nibo tai type cast kora lagbe
       try
       {
           Conn conn = new Conn();
           
           String query= "insert into employees values ('"+age+"', '"+n+"','"+gender+"' ,'"+job+"' ,'"+salary+"', '"+phone+"', '"+email+"', '"+nid+"')";
           
           conn.s.executeUpdate(query);
           JOptionPane.showMessageDialog(null, "Employee added successfully");
           
           setVisible(false);
           
       }
       catch (Exception e) 
       {
           e.printStackTrace();
       }
        }
        else {
                setVisible(false);
           }
    }
    public static void main(String[] args) 
    {
       new AddEmployee();
    }
}
