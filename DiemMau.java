package THBUOI4;

import java.util.Scanner;

public class DiemMau extends Diem {
	 private String mau;
	 
	 public DiemMau() {
		 super();
		 this.mau = new String();
	 }
	 
	 public DiemMau(int x, int y, String mau){
		 super(x,y);
		 this.mau = mau;
	 }
	 
	 public void ganMau(String mau) {
		 this.mau= mau;
	 }
	 // @overiding
	 
	 public void nhap() {
		 Scanner s = new Scanner(System.in);
		 super.nhapDiem();
		 System.out.println("Nhập màu: ");
		 mau = s.nextLine();
	 }
	 
	 public void hienThi() {
		 super.hienThi();
		 System.out.print("-> "+ mau);
	 }
	 
}
