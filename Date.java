package Student;

import java.util.Scanner;

public class Date {
	public static Scanner sc = new Scanner(System.in);
	int in[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	private int d, m, y;
	
	public Date(){
		d =1;
		m =1;
		y =1;
	}
	
	public Date(int d, int m, int y){
		this.d = d;
		this.m = m;
		this.y = y;
	}												
	
	public boolean hopLe() {
		if ((y%4==0 && y%100!=0) || y % 400==0) 
			in[2] =29;
		if(m < 1 || m >12)
			return false;
		else
			return (d >=1 && d<=in[m]);
	}
	public void nhap() {
		do {
			System.out.print("Nhập ngày: "); 
			d = sc.nextInt();
			System.out.print("Nhập tháng: "); 
			m = sc.nextInt();
			System.out.print("Nhập năm: "); 
			y = sc.nextInt();
			if(!this.hopLe())
				System.out.println("Lỗi. Vui lòng nhập lại! ");
		} while(!this.hopLe());
	}
		
	public void in() {
		System.out.println("Ngày: " +this.d +"/"+ this.m +"/"+ this.y);
	}
		
	public Date ngayHomSau() {
		Date tmr = new Date();
		if ((y%4==0 && y%100!=0) || y % 400==0) 
			in[2] =29;
		if(d >=1 && d<=in[m]) {
			tmr.d = d + 1;
			tmr.m = m;
			tmr.y = y;
		}
		else {
			tmr.d = 1;
			tmr.m = m+1;
			tmr.y = y;
		}
			
		if(tmr.m == 13) {
			tmr.m = 1;
			tmr.y++ ;
		}
		return tmr;
	}
	public Date congNgay(int n) {
		Date sd = new Date(d,m,y);
		for(int i=0; i<n; i++)
			sd = sd.ngayHomSau();
		System.out.println("Sau cộng khi " + n + " ngày ");
		return sd;
	}

	public int getD(){
		return d;
	}
	
	public int getM(){
		return m;
	}
	
	public int getY(){
		return y;
	}
}

