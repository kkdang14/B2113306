package THBUOI4;

public class SDDiemMau {
	public static void main(String[] args) {
		DiemMau A= new DiemMau(5,10,"Trắng");
		System.out.print("A");
		A.hienThi();
		System.out.print("\n");
		
		DiemMau B= new DiemMau();
		B.nhap();
		B.doiDiem(8, 10);
		System.out.print("B");
		B.hienThi();
		B.ganMau("Vàng");
		System.out.print("\n");
		System.out.println("Điểm màu mới:");
		System.out.print("B");
		B.hienThi();
	}
}
