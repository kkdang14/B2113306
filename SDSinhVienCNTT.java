package Student;

import java.util.Scanner;

public class SDSinhVienCNTT {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n;
		String email;
		System.out.println("Nhập số sinh viên: ");
		n =s.nextInt();
		
		SinhVienCNTT SV[] = new SinhVienCNTT[n];
		for(int i=0; i<n; i++) {
			SV[i] = new SinhVienCNTT();
			System.out.println("Nhập thông tin sinh viên CNTT thứ "+ (i+1)+ ": ");
			SV[i].nhapThongTin();
		}
		System.out.print("Nhập email cần tìm: ");
		email =s.nextLine();
		for(int i=0; i<n; i++) {
			if(SV[i].getEmail().compareTo(email)==0) {
				System.out.println("Email của sinh viên thứ "+ (i+1) +": "+ email);
				System.out.println(SV[i].kqHocTap());
				break;
			}
		}
 	}
}
