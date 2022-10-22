package THBUOI4;

public class Bo extends ConVat{
	//@Overide
	public void Keu() {
		System.out.println("+ Con bò kêu: Mòooo...!");
	}
	
	public void nhapThongTin() {
		System.out.println("Nhập thông tin bò: ");
		super.nhapThongTin();
	}
	
	public void hienThi() {
		System.out.println("Thông tin bò: ");
		super.hienThi();
	}
}