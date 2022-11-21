
package hotel.management.system;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Dashboard extends JFrame{
    Dashboard(){
        setBounds(0,0,1550,800);
        
        setLayout(null);
        ImageIcon i1=new ImageIcon(ClassLoader.getSystemResource("icons/third.jpg"));
        Image i2=i1.getImage().getScaledInstance(1550, 1000, Image.SCALE_DEFAULT);
        ImageIcon i3=new ImageIcon(i2);
        JLabel image= new JLabel(i3);
        image.setBounds(0,0,1550,800);
        add(image);
        
        JLabel text = new JLabel ("The PARADISE HOTEL WELCOMES YOU");
        text.setBounds(400,80,1000,50);
        text.setFont(new Font("Tahoma",Font.ITALIC,46));
        text.setForeground(Color.WHITE);
        image.add(text);
        
        JMenuBar mb = new JMenuBar();
        mb.setBounds(0,0,1550,30);
        image.add(mb);
        
        JMenu hotel = new JMenu("HOTEL MANAGEMENT");
        hotel.setForeground(Color.red);
        mb.add(hotel);
     
        JMenuItem reception = new JMenuItem("RECEPTION");
        hotel.add(reception);
        
        reception.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent ae)
            {
                try
                {
                    new Reception().setVisible(true);
                }
                catch(Exception e ){}
            }
        });
        
        
        JMenu admin = new JMenu("ADMIN");
        admin.setForeground(Color.BLUE);
        mb.add(admin);
        
        JMenuItem addemployee = new JMenuItem("ADD EMPLOYEE");
        admin.add(addemployee);
        
        addemployee.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent ae)
            {
                try
                {
                    new AddEmployee().setVisible(true);
                }
                catch(Exception e ){}
            }
        });
        
        JMenuItem addrooms = new JMenuItem("ADD ROOMS");
        admin.add(addrooms);
        
        addrooms.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent ae)
            {
                try
                {
                    new AddRooms().setVisible(true);
                }
                catch(Exception e ){}
            }
        });
        
        
        JMenuItem adddrivers = new JMenuItem("ADD DRIVERS");
        admin.add(adddrivers);
        
        adddrivers.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent ae)
            {
                try
                {
                    new AddDriver().setVisible(true);
                }
                catch(Exception e ){}
            }
        });
        
        setVisible(true);
                
    }
     public static void main(String[] args){
         new Dashboard();
     }
}
