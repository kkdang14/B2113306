package Student;

import java.util.Scanner;

public class SinhVienCNTT extends SinhVien {
	private String taikhoan;
	private String matkhau;
	private String email;
	
	SinhVienCNTT(){
		super();
		taikhoan = new String();
		matkhau = new String();
		email = new String();
	}
	
	public SinhVienCNTT(String ms, String name, Date bn, int sohp, String[] thp, String[] dhp, String tk, String mk, String email) {
		super(ms, name, bn, sohp, thp, dhp);
		this.taikhoan = tk;
		this.matkhau = mk;
		this.email = email;	
	}
	
	public SinhVienCNTT(SinhVienCNTT sv) {
		taikhoan = new String(sv.taikhoan);
		matkhau = new String(sv.matkhau);
		email =  new String(sv.email);
	}
	
	public void nhapThongTin() {
		super.nhapThongTin();
		super.nhapDiem();
		
		Scanner s = new Scanner(System.in);
		System.out.println("+ Nhập tài khoản ELCIT: ");
		taikhoan = s.nextLine();
		System.out.println("+ Nhập mật khẩu ELCIT: ");
		matkhau = s.nextLine();
		System.out.println("+ Nhập email: ");
		email = s.nextLine();	
	}
	
	public String toString() {
		String result;
		result = super.toString();
		result = "+ Tài khoản ELCIT: "+ taikhoan +"\n";
		result = "+ Mật khẩu ELCIT: ********** \n";
		result = "+ Email: "+ email +"\n";
		
		return result;
	}
	
	public void doiMatKhau(String newpass) {
		this.matkhau= newpass;
	}
	
	public String getEmail() {
		return email;
	}
	
	public String kqHocTap() {
		String result;
		
		result = "+ Tài khoản ELCIT: "+ taikhoan +"\n";
		result += "+ Điểm các học phần : " + "\n";
		for(int i=0; i<sohp; i++) {
			result +="  "+ tenhp.get(i) +": "+ diemhp.get(i) +"\n";
		}
		return result;
	}

	public void lala(){
		return lala;
	}

}
