package Student;

import java.util.ArrayList;
import java.util.Scanner;

public class SinhVien {
	public Scanner s = new Scanner(System.in);
	private String mssv, hoten;
	private Date ngsinh;
	protected int sohp;
	protected ArrayList<String> tenhp;
	protected ArrayList<String> diemhp;
	
	SinhVien(){
		mssv= null;
		hoten= null;
		ngsinh = new Date();
		sohp = 0;
		tenhp = new ArrayList<String>();
		diemhp = new ArrayList<String>();	
	}
	
	SinhVien(String ms, String name, Date bn, int sohp, String[] thp, String[] dhp){
		 mssv = ms;
		 hoten = name;
		 ngsinh = new Date(bn.getD(), bn.getM(), bn.getY());
		 tenhp = new ArrayList<String>();
		 diemhp = new ArrayList<String>();
		 for(int i=0; i<sohp; i++) {
			 tenhp.add(thp[i]);
			 diemhp.add(dhp[i]);
		 }
	}
	
	public String getHoTen() {
		return hoten;
	}
	
	public String toString() {
		String rs= "";
		rs += "+ MSSV: " + mssv +"\n";
		rs += "+ Họ tên: " + hoten +"\n";
		rs += "+ Ngày sinh: "+ ngsinh.getD()+"/"+ ngsinh.getM()+"/"+ngsinh.getY() +"\n";
		rs += "+ Số học phần: "+ sohp +"\n";
		rs += "+ Điểm các học phần: " + "\n";
		for(int i=0; i<sohp; i++) {
			rs +="  "+ tenhp.get(i) +": "+ diemhp.get(i) +"\n";
		}
		return rs;
	}
	
	public void nhapThongTin() {
		System.out.println("Nhập MSSV: ");
		mssv = s.nextLine();
		System.out.println("Nhập họ tên: ");
		hoten = s.nextLine();
		System.out.println("Nhập ngày sinh: ");
		ngsinh.nhap();
	}
	
	public void nhapDiem() {
		System.out.println("Nhập số học phần: ");
		sohp = s.nextInt();
		s.nextLine();
		for(int i=0; i<sohp; i++) {
			String tmpa, tmpb;
			System.out.println("Nhập tên học phần thứ "+ (i+1) +": ");
			tmpa=s.nextLine();
			System.out.println("Nhập điểm học phần thứ "+ (i+1) +": ");
			tmpb= s.nextLine();
			tenhp.add(tmpa);
			diemhp.add(tmpb);
		}
	}
	
	public double diemTB() {
		double sum = 0;
		for(int i=0; i<sohp; i++){
			switch(diemhp.get(i)){
				case "A":
					sum+=4;
					break;
				case "B+":
					sum+=3.5;
					break;
				case "B":
					sum+=3;
					break;
				case "C+":
					sum+=2.5;
					break;
				case "C":
					sum+=2;
					break;
				case "D+": 
					sum+=1.5;
					break;
				case "D":
					sum+=1;
					break;
				default:
					break;
			}
		}
		return sum/(float)sohp;
	}
	
	public void themHocPhan() {
		String tmpa, tmpb;
		System.out.println("Nhap ten hoc phan can them: ");
		tmpa=s.nextLine();
		System.out.println("Nhap diem cua hoc phan can them: ");
		tmpb= s.nextLine();
		tenhp.add(tmpa);
		diemhp.add(tmpb);
		sohp++;
	}
	
	public void xoaHocPhan() {
		String tmp;
		System.out.println("Nhap hoc phan can xoa: ");
		tmp = s.nextLine();
		for(int i=0; i<sohp; i++) {
			if(tenhp.get(i).equals(tmp)) {
				tenhp.remove(i);
				diemhp.remove(i);
				sohp--;
			}
		}
	}

	public diemrenluyen(){
		return 0;
	}
}
