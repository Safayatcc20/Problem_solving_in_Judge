package Cafe;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import javax.swing.ComboBoxModel;
import javax.swing.JScrollBar;

/**
 *
 * @author shadman
 */
public class display_books extends javax.swing.JPanel {

    /**
     * Creates new form ManageBooksPanel
     */

    FoodView booklist = null;
    public display_books() {
        initComponents();
        set_genre_combo();
        update_list();
        JScrollBar verticalScrollBar = ScrollView.getVerticalScrollBar();
        verticalScrollBar.setUnitIncrement(20);
        verticalScrollBar.setBlockIncrement(200);
    }

    public void set_genre_combo() {
        cmb_genre.removeAll();
        cmb_genre.addItem("");
        try {
            Connection con = new DBConnection().getConnection();
            Statement st = con.createStatement();
            ResultSet rs = st.executeQuery("SELECT DISTINCT category FROM item_details");
            while (rs.next()) {
                cmb_genre.addItem(rs.getString("category"));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void update_list() {
        String name = txt_name.getText();
//        String author = txt_author.getText();
        String genre = cmb_genre.getSelectedIndex() == -1 ? "" : cmb_genre.getItemAt(cmb_genre.getSelectedIndex());
        int price_from = txt_pricefrom.getText().equals("") ? 0 : Integer.parseInt(txt_pricefrom.getText());
        int price_to = txt_priceto.getText().equals("") ? 0 : Integer.parseInt(txt_priceto.getText());
        float rating_from = txt_ratingfrom.getText().equals("") ? 0.0f : Float.parseFloat(txt_ratingfrom.getText());
        float rating_to = txt_ratingto.getText().equals("") ? 0.0f : Float.parseFloat(txt_ratingto.getText());
//        int year_from = txt_yearfrom.getText().equals("")  ? 0 : Integer.parseInt(txt_yearfrom.getText());
//        int year_to = txt_yearto.getText().equals("") ? 0 : Integer.parseInt(txt_yearto.getText());

        var books = new ArrayList<Food>();

        try {
            Connection con = new DBConnection().getConnection();
            String query = "SELECT * FROM item_details WHERE item_name LIKE ? AND category LIKE ? AND price BETWEEN ? AND ? AND item_rating BETWEEN ? AND ?";
            var st = con.prepareStatement(query);
            st.setString(1, name.equals("") ? "%" : "%"+name+"%");
//            st.setString(2, author.equals("") ? "%" : "%"+author+"%");
            st.setString(2, genre.equals("") ? "%" : "%"+genre+"%");
            st.setInt(3, price_from);
            st.setInt(4, price_to == 0 ? 999999999 : price_to);
            st.setFloat(5, rating_from);
            st.setFloat(6, rating_to == 0 ? 9 : rating_to);
//            st.setInt(8, year_from);
//            st.setInt(9, year_to == 0 ? 99999 : year_to);

            var rs = st.executeQuery();
            while (rs.next()) {
                books.add(new Food(rs));
            }
            update_res_panel(new FoodView(books));
        } catch (Exception e) {
            e.printStackTrace();
        }
        
    }

    public void update_res_panel(FoodView bv) {
        if (booklist != null) ScrollView.getViewport().remove(booklist);
        ScrollView.getViewport().add(bv);
        this.validate();
        this.repaint();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jPanel2 = new javax.swing.JPanel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        btn_search = new necesario.RSMaterialButtonCircle();
        txt_name = new app.bolivia.swing.JCTextField();
        txt_author = new app.bolivia.swing.JCTextField();
        txt_yearfrom = new app.bolivia.swing.JCTextField();
        txt_yearto = new app.bolivia.swing.JCTextField();
        jLabel8 = new javax.swing.JLabel();
        txt_ratingfrom = new app.bolivia.swing.JCTextField();
        txt_ratingto = new app.bolivia.swing.JCTextField();
        jLabel9 = new javax.swing.JLabel();
        txt_pricefrom = new app.bolivia.swing.JCTextField();
        jLabel10 = new javax.swing.JLabel();
        txt_priceto = new app.bolivia.swing.JCTextField();
        cmb_genre = new javax.swing.JComboBox<>();
        ScrollView = new javax.swing.JScrollPane();

        setBackground(new java.awt.Color(255, 255, 255));
        setMinimumSize(new java.awt.Dimension(1200, 760));
        setPreferredSize(new java.awt.Dimension(1200, 760));
        setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel1.setFont(new java.awt.Font("Centaur", 0, 32)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(251, 51, 51));
        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel1.setText("Books");
        add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(450, 0, 180, 50));

        jPanel2.setBackground(new java.awt.Color(255, 255, 255));
        jPanel2.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel2.setBackground(new java.awt.Color(255, 255, 255));
        jLabel2.setFont(new java.awt.Font("Glass Antiqua", 0, 20)); // NOI18N
        jLabel2.setForeground(new java.awt.Color(51, 51, 51));
        jLabel2.setText("Name");
        jPanel2.add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 40, -1, -1));

        jLabel3.setBackground(new java.awt.Color(255, 255, 255));
        jLabel3.setFont(new java.awt.Font("Glass Antiqua", 0, 20)); // NOI18N
        jLabel3.setForeground(new java.awt.Color(51, 51, 51));
        jLabel3.setText("Author");
        jPanel2.add(jLabel3, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 80, -1, -1));

        jLabel4.setBackground(new java.awt.Color(255, 255, 255));
        jLabel4.setFont(new java.awt.Font("Glass Antiqua", 0, 20)); // NOI18N
        jLabel4.setForeground(new java.awt.Color(51, 51, 51));
        jLabel4.setText("Genre");
        jPanel2.add(jLabel4, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 120, -1, -1));

        jLabel5.setBackground(new java.awt.Color(255, 255, 255));
        jLabel5.setFont(new java.awt.Font("Glass Antiqua", 0, 20)); // NOI18N
        jLabel5.setForeground(new java.awt.Color(51, 51, 51));
        jLabel5.setText("published");
        jPanel2.add(jLabel5, new org.netbeans.lib.awtextra.AbsoluteConstraints(550, 30, -1, -1));

        jLabel6.setBackground(new java.awt.Color(255, 255, 255));
        jLabel6.setFont(new java.awt.Font("Glass Antiqua", 0, 20)); // NOI18N
        jLabel6.setForeground(new java.awt.Color(51, 51, 51));
        jLabel6.setText("rating");
        jPanel2.add(jLabel6, new org.netbeans.lib.awtextra.AbsoluteConstraints(550, 70, -1, -1));

        jLabel7.setBackground(new java.awt.Color(255, 255, 255));
        jLabel7.setFont(new java.awt.Font("Glass Antiqua", 0, 20)); // NOI18N
        jLabel7.setForeground(new java.awt.Color(51, 51, 51));
        jLabel7.setText("price");
        jPanel2.add(jLabel7, new org.netbeans.lib.awtextra.AbsoluteConstraints(550, 110, -1, -1));

        btn_search.setBackground(new java.awt.Color(251, 51, 51));
        btn_search.setIcon(new javax.swing.ImageIcon(getClass().getResource("/icons/icons8-search-64 white.png"))); // NOI18N
        btn_search.setText("Search");
        btn_search.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                btn_searchMouseClicked(evt);
            }
        });
        btn_search.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn_searchActionPerformed(evt);
            }
        });
        jPanel2.add(btn_search, new org.netbeans.lib.awtextra.AbsoluteConstraints(1030, 60, 130, 50));

        txt_name.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 2, 0, new java.awt.Color(51, 102, 255)));
        txt_name.setPlaceholder("Book Name");
        jPanel2.add(txt_name, new org.netbeans.lib.awtextra.AbsoluteConstraints(100, 30, 330, 30));

        txt_author.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 2, 0, new java.awt.Color(51, 102, 255)));
        txt_author.setPlaceholder("Author Name");
        txt_author.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                txt_authorActionPerformed(evt);
            }
        });
        jPanel2.add(txt_author, new org.netbeans.lib.awtextra.AbsoluteConstraints(100, 70, 330, 30));

        txt_yearfrom.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 2, 0, new java.awt.Color(51, 102, 255)));
        txt_yearfrom.setPlaceholder("From Year");
        txt_yearfrom.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                txt_yearfromActionPerformed(evt);
            }
        });
        jPanel2.add(txt_yearfrom, new org.netbeans.lib.awtextra.AbsoluteConstraints(650, 30, 150, 30));

        txt_yearto.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 2, 0, new java.awt.Color(51, 102, 255)));
        txt_yearto.setPlaceholder("To Year");
        jPanel2.add(txt_yearto, new org.netbeans.lib.awtextra.AbsoluteConstraints(850, 20, 150, 30));

        jLabel8.setBackground(new java.awt.Color(255, 255, 255));
        jLabel8.setFont(new java.awt.Font("Glass Antiqua", 0, 24)); // NOI18N
        jLabel8.setText("-");
        jPanel2.add(jLabel8, new org.netbeans.lib.awtextra.AbsoluteConstraints(820, 30, 10, -1));

        txt_ratingfrom.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 2, 0, new java.awt.Color(51, 102, 255)));
        txt_ratingfrom.setPlaceholder("From Rating");
        jPanel2.add(txt_ratingfrom, new org.netbeans.lib.awtextra.AbsoluteConstraints(650, 60, 150, 30));

        txt_ratingto.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 2, 0, new java.awt.Color(51, 102, 255)));
        txt_ratingto.setPlaceholder("To Rating");
        jPanel2.add(txt_ratingto, new org.netbeans.lib.awtextra.AbsoluteConstraints(850, 60, 150, 30));

        jLabel9.setBackground(new java.awt.Color(255, 255, 255));
        jLabel9.setFont(new java.awt.Font("Glass Antiqua", 0, 24)); // NOI18N
        jLabel9.setText("-");
        jPanel2.add(jLabel9, new org.netbeans.lib.awtextra.AbsoluteConstraints(820, 70, 10, -1));

        txt_pricefrom.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 2, 0, new java.awt.Color(51, 102, 255)));
        txt_pricefrom.setPlaceholder("From Price");
        jPanel2.add(txt_pricefrom, new org.netbeans.lib.awtextra.AbsoluteConstraints(650, 100, 150, 30));

        jLabel10.setBackground(new java.awt.Color(255, 255, 255));
        jLabel10.setFont(new java.awt.Font("Glass Antiqua", 0, 24)); // NOI18N
        jLabel10.setText("-");
        jPanel2.add(jLabel10, new org.netbeans.lib.awtextra.AbsoluteConstraints(820, 110, 10, -1));

        txt_priceto.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 2, 0, new java.awt.Color(51, 102, 255)));
        txt_priceto.setPlaceholder("To Price");
        jPanel2.add(txt_priceto, new org.netbeans.lib.awtextra.AbsoluteConstraints(850, 100, 150, 30));

        jPanel2.add(cmb_genre, new org.netbeans.lib.awtextra.AbsoluteConstraints(100, 120, 330, -1));

        add(jPanel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 50, 1200, 160));

        ScrollView.setBackground(new java.awt.Color(255, 255, 255));
        ScrollView.setHorizontalScrollBarPolicy(javax.swing.ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
        add(ScrollView, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 210, 1200, 550));
    }// </editor-fold>//GEN-END:initComponents

    private void txt_authorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_txt_authorActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_txt_authorActionPerformed

    private void btn_searchMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_btn_searchMouseClicked
        // TODO add your handling code here:
        update_list();
    }//GEN-LAST:event_btn_searchMouseClicked

    private void txt_yearfromActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_txt_yearfromActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_txt_yearfromActionPerformed

    private void btn_searchActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn_searchActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_btn_searchActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JScrollPane ScrollView;
    private necesario.RSMaterialButtonCircle btn_search;
    private javax.swing.JComboBox<String> cmb_genre;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JPanel jPanel2;
    private app.bolivia.swing.JCTextField txt_author;
    private app.bolivia.swing.JCTextField txt_name;
    private app.bolivia.swing.JCTextField txt_pricefrom;
    private app.bolivia.swing.JCTextField txt_priceto;
    private app.bolivia.swing.JCTextField txt_ratingfrom;
    private app.bolivia.swing.JCTextField txt_ratingto;
    private app.bolivia.swing.JCTextField txt_yearfrom;
    private app.bolivia.swing.JCTextField txt_yearto;
    // End of variables declaration//GEN-END:variables
}
