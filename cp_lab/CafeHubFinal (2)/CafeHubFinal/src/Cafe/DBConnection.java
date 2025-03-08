package Cafe;
import java.sql.*;

public class DBConnection {
    ResultSet Rs = null, rs1 = null;
    Connection con = null;
    PreparedStatement St = null, st1 = null;
    
    public Connection getConnection() {
        if (con != null) return con;
        String url = "jdbc:mysql://localhost:3306/cafe_ms";
        String username = "root";
        String password = "hellowin";
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection connection = DriverManager.getConnection(url, username, password);

            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/cafe_ms", "root", "hellowin");            
        }catch(Exception e) {
            e.printStackTrace();
        }
        return con;
    }
}
