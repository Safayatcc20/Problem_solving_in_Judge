package Cafe;
import java.sql.ResultSet;
import java.sql.SQLException;


public class Food {
//    public int book_id;
    public int Iid;
    public String Iname;
    public String Icategory;
    public int Iprice;
    public float rating;
//    public int quantity;
//    public String genre;
//    public float rating;
//    public int year;
//    public String desc;

    private void initialize_data(int Iid, String Iname, String Icategory, int Iprice, float rating) {
        this.Iid = Iid;
        this.Iname = Iname;
        this.Icategory = Icategory;
        this.Iprice = Iprice;
        this.rating = rating;
    }

    public Food(int id, String name, String category, int price, float rating) {
        initialize_data(id, name, category, price, rating);
    }

    public Food(ResultSet rs) throws SQLException {
        try {
            int row_id = rs.getInt("item_id");
            String row_name = rs.getString("item_name");
            String row_cat = rs.getString("category");
//            String row_g = rs.getString("genre");
            int row_price = rs.getInt("price");
//            int row_quantity = rs.getInt("quantity");
            float row_rating = rs.getFloat("item_rating");
//            int row_year = rs.getInt("year");
//            String row_desc = rs.getString("description");
            initialize_data(row_id, row_name, row_cat, row_price, row_rating);
        } catch (SQLException e) {
            throw e;
        }

    }
}
