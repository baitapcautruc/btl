#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>
#include<string.h>
 
using namespace std;
 
const int WIDTH = 15;
 
class SinhVien {
private:
	string mssv;
	string hoVaTen;
	string gioiTinh;
 
	double toan, ly, hoa, DTB;
 
public:
	SinhVien(string mssv, string hoVaTen, string gioiTinh, double toan, double ly, double hoa) {
		this->mssv = mssv;
		this->hoVaTen = hoVaTen;
		this->toan = toan;
		this->gioiTinh = gioiTinh;
		this->ly = ly;
		this->hoa = hoa;
		DTB = round((toan + ly + hoa) / 3 * 100) / 100;
	}
 
	SinhVien() {}
 
	string getMssv() {
		return mssv;
	}
 
	string getHoVaTen() {
		return hoVaTen;
	}
 
	double getToan() {
		return toan;
	}
 
	double getLy() {
		return ly;
	}
 
	double getHoa() {
		return hoa;
	}
 
	double getDTB() {
		return DTB;
	}
 
	string getGioiTinh() {
		return gioiTinh;
	}
 
	void nhap() {
		do {
			cout << "Ma so sinh vien: ";
			// getline de nhap chuoi 
			getline(cin, this->mssv);
			if (mssv == "" || mssv.length() == 0) {
				cout << "Khong duoc de trong ma sinh vien! Vui long nhap lai" << endl;
			}
		} while (mssv == "" || mssv.length() == 0);
 
 
		do {
			cout << "Ho va ten: ";
			getline(cin, this->hoVaTen);
			if (hoVaTen == "" || hoVaTen.length() == 0) {
				cout << "Khong duoc de trong ho ten! Vui long nhap lai" << endl;
			}
		} while (hoVaTen == "" || hoVaTen.length() == 0);
 
		int luaChon = 0;
		cout << "Gioi tinh" << endl;
		do {
			cout << "\t1. Nam" << endl;
			cout << "\t2. Nu" << endl;
			cout << "\t3. Khac" << endl;
			cout << "\tNhap lua chon: ";
			cin >> luaChon;
			if (luaChon != 1 && luaChon != 2 && luaChon != 3) {
				cout << "Lua chon khong hop le! Vui long chon lai" << endl;
			}
		} while (luaChon != 1 && luaChon != 2 && luaChon != 3);
		if (luaChon == 1) {
			gioiTinh = "Nam";
		}
		else if (luaChon == 2) {
			gioiTinh = "Nu";
		}
		else {
			gioiTinh = "Khac";
		}
 
 
		do {
			cout << "Diem toan: ";
			cin >> toan;
			if (toan < 0 || toan > 10) {
				cout << "Diem khong hop le! Vui long nhap lai" << endl;
			}
		} while (toan < 0 || toan > 10);
 
		do {
			cout << "Diem ly: ";
			cin >> ly;
			if (ly < 0 || ly > 10) {
				cout << "Diem khong hop le! Vui long nhap lai" << endl;
			}
 
		} while (ly < 0 || ly > 10);
 
		do {
			cout << "Diem hoa: ";
			cin >> hoa;
			if (hoa < 0 || hoa > 10) {
				cout << "Diem khong hop le! Vui long nhap lai" << endl;
			}
		} while (hoa < 0 || hoa > 10);
 
 
 
 
 
		DTB = (toan + ly + hoa) / 3;
	}
 
 
};
 
struct Node {
	SinhVien sv;
	Node* next;
	Node(SinhVien sv) {
		this->sv = sv;
		this->next = NULL;
	}
};
 
class DanhSachLienKetDon {
private:
	Node* head;
public:
	DanhSachLienKetDon() {
		this->head = NULL;
	}
 
	Node* getHead() {
		return head;
	}
 
	// 2
	void xuat() {
		cout << setw(WIDTH) << "Ma sinh vien" << "|"
			<< setw(WIDTH) << "Ho va ten" << "|"
			<< setw(WIDTH) << "Gioi Tinh" << "|"
			<< setw(WIDTH) << "Toan" << "|"
			<< setw(WIDTH) << "Ly" << "|"
			<< setw(WIDTH) << "Hoa" << "|"
			<< setw(WIDTH) << "Diem trung binh" << endl;
		Node* temp = head;
		while (temp != NULL) {
			cout << setw(WIDTH) << temp->sv.getMssv() << "|"
				<< setw(WIDTH) << temp->sv.getHoVaTen() << "|"
				<< setw(WIDTH) << temp->sv.getGioiTinh() << "|"
				<< setw(WIDTH) << temp->sv.getToan() << "|"
				<< setw(WIDTH) << temp->sv.getLy() << "|"
				<< setw(WIDTH) << temp->sv.getHoa() << "|"
				<< setw(WIDTH) << temp->sv.getDTB() << endl;
			temp = temp->next;
		}
	}
 
	// 3
	void sinhVienXepLoaiYeu() {
		cout << setw(WIDTH) << "Ma sinh vien" << "|"
			<< setw(WIDTH) << "Ho va ten" << "|"
			<< setw(WIDTH) << "Gioi Tinh" << "|"
			<< setw(WIDTH) << "Toan" << "|"
			<< setw(WIDTH) << "Ly" << "|"
			<< setw(WIDTH) << "Hoa" << "|"
			<< setw(WIDTH) << "Diem trung binh" << endl;
		Node* temp = head;
		while (temp != NULL) {
			if (temp->sv.getDTB() < 4) {
				cout << setw(WIDTH) << temp->sv.getMssv() << "|"
					<< setw(WIDTH) << temp->sv.getHoVaTen() << "|"
					<< setw(WIDTH) << temp->sv.getGioiTinh() << "|"
					<< setw(WIDTH) << temp->sv.getToan() << "|"
					<< setw(WIDTH) << temp->sv.getLy() << "|"
					<< setw(WIDTH) << temp->sv.getHoa() << "|"
					<< setw(WIDTH) << temp->sv.getDTB() << endl;
			}
			temp = temp->next;
		}
	}
 
 
	// 4
	void sinhVienCoDTBTren5() {
		cout << setw(WIDTH) << "Ma sinh vien" << "|"
			<< setw(WIDTH) << "Ho va ten" << "|"
			<< setw(WIDTH) << "Gioi Tinh" << "|"
			<< setw(WIDTH) << "Toan" << "|"
			<< setw(WIDTH) << "Ly" << "|"
			<< setw(WIDTH) << "Hoa" << "|"
			<< setw(WIDTH) << "Diem trung binh" << endl;
		Node* temp = head;
		while (temp != NULL) {
			if (temp->sv.getDTB() > 5) {
				cout << setw(WIDTH) << temp->sv.getMssv() << "|"
					<< setw(WIDTH) << temp->sv.getHoVaTen() << "|"
					<< setw(WIDTH) << temp->sv.getGioiTinh() << "|"
					<< setw(WIDTH) << temp->sv.getToan() << "|"
					<< setw(WIDTH) << temp->sv.getLy() << "|"
					<< setw(WIDTH) << temp->sv.getHoa() << "|"
					<< setw(WIDTH) << temp->sv.getDTB() << endl;
			}
			temp = temp->next;
		}
	}
 
	void themDau(SinhVien sv) {
		Node* newNode = new Node(sv);
		if (head == NULL) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}
 
	void themCuoi(SinhVien sv) {
		Node* newNode = new Node(sv);
		if (head == NULL) {
			head = newNode;
		}
		else {
			Node* currentNode = head;
			while (currentNode->next != NULL) {
				currentNode = currentNode->next;
			}
			currentNode->next = newNode;
		}
	}
 
	// 6
	void xoaDau() {
		if (head == NULL) {
			return;
		}
		Node* headNode = head;
		head = head->next;
		delete headNode;
	}
 
	// 7
	void xoaCuoi() {
		if (head == NULL) {
			return;
		}
		// khi co 1 thang trong day
		if (head->next == NULL) {
			delete head;
			head = NULL;
			return;
		}
		Node* currentNode = head;
		while (currentNode->next->next != NULL) {
			currentNode = currentNode->next;
		}
		Node* delNode = currentNode->next;
		currentNode->next = NULL;
		delete delNode;
	}
 
 
	// 8
	void xoaToanBoDanhSach() {
		if (head == NULL) {
			return;
		}
 
		Node* currentNode = head;
		while (head != NULL) {
			head = head->next;
			delete currentNode;
			currentNode = head;
		}
		delete head;
		head == NULL;
	}
 
 
	// 5
	SinhVien timSinhVienTheoMa(string x) {
		SinhVien sinhVienTraVe;
		Node* temp = head;
		while (temp != NULL) {
			if (temp->sv.getMssv() == x) {
				cout << setw(WIDTH) << "Ma sinh vien" << "|"
					<< setw(WIDTH) << "Ho va ten" << "|"
					<< setw(WIDTH) << "Gioi Tinh" << "|"
					<< setw(WIDTH) << "Toan" << "|"
					<< setw(WIDTH) << "Ly" << "|"
					<< setw(WIDTH) << "Hoa" << "|"
					<< setw(WIDTH) << "Diem trung binh" << endl;
				cout << setw(WIDTH) << temp->sv.getMssv() << "|"
					<< setw(WIDTH) << temp->sv.getHoVaTen() << "|"
					<< setw(WIDTH) << temp->sv.getGioiTinh() << "|"
					<< setw(WIDTH) << temp->sv.getToan() << "|"
					<< setw(WIDTH) << temp->sv.getLy() << "|"
					<< setw(WIDTH) << temp->sv.getHoa() << "|"
					<< setw(WIDTH) << temp->sv.getDTB() << endl;
				sinhVienTraVe = temp->sv;
				return sinhVienTraVe;
			}
			temp = temp->next;
		}
		cout << "Khong tim thay sinh vien" << endl;
		return sinhVienTraVe;
	}
	// 1 2 3 4 5
	void sapXepTheoDTBTangDan() {
		for (Node* i = head; i->next != NULL; i = i->next) {
			for (Node* j = i->next; j != NULL; j = j->next) {
				if (i->sv.getDTB() > j->sv.getDTB()) {
					SinhVien temp = i->sv;
					i->sv = j->sv;
					j->sv = temp;
				}
			}
		}
	}
 
	void timKiemSinhVienTheoTen(string ten) {
		Node* temp = head;
		bool check = false;
		while (temp != NULL) {
			// Ham find co trong thu vien string
			// Khong tim ra thi se tra ve -1
 
			if (temp->sv.getHoVaTen().find(ten) != -1) {
				if (!check) {
					cout << setw(WIDTH) << "Ma sinh vien" << "|"
						<< setw(WIDTH) << "Ho va ten" << "|"
						<< setw(WIDTH) << "Gioi Tinh" << "|"
						<< setw(WIDTH) << "Toan" << "|"
						<< setw(WIDTH) << "Ly" << "|"
						<< setw(WIDTH) << "Hoa" << "|"
						<< setw(WIDTH) << "Diem trung binh" << endl;
				}
				cout << setw(WIDTH) << temp->sv.getMssv() << "|"
					<< setw(WIDTH) << temp->sv.getHoVaTen() << "|"
					<< setw(WIDTH) << temp->sv.getGioiTinh() << "|"
					<< setw(WIDTH) << temp->sv.getToan() << "|"
					<< setw(WIDTH) << temp->sv.getLy() << "|"
					<< setw(WIDTH) << temp->sv.getHoa() << "|"
					<< setw(WIDTH) << temp->sv.getDTB() << endl;
				check = true;
			}
			temp = temp->next;
		}
		if (!check) {
			cout << "Khong tim thay sinh vien" << endl;
		}
	}
 
	void initData() {
		SinhVien sv1("A12345", "Nguyen Van A", "Nam", 1, 2, 3);
		SinhVien sv2("B12346", "Nguyen Van B", "Nu", 7, 6, 7);
		SinhVien sv3("C12345", "Nguyen Van C", "Nam", 6, 1, 2);
		SinhVien sv4("D12345", "Nguyen Van D", "Nam", 1, 2, 3);
		SinhVien sv5("E12346", "Nguyen Van E", "Khac", 1, 1, 1);
		SinhVien sv6("123457", "Nguyen Van F", "Nu", 10, 10, 9);
		SinhVien sv7("C12345", "Nguyen Van C", "Nu", 3, 2, 1);
		this->themCuoi(sv1);
		this->themCuoi(sv2);
		this->themCuoi(sv3);
		this->themCuoi(sv4);
		this->themCuoi(sv5);
		this->themCuoi(sv6);
		this->themCuoi(sv7);
	}
};
 
// Head la danh sach, mssv la tim trong danh sach do co chua khong
bool isMssv(Node* head, string mssv) {
	Node* temp = head;
	while (temp != NULL) {
		if (temp->sv.getMssv() == mssv) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}
 
 
int main() {
	DanhSachLienKetDon ds;
	ds.initData();
 
	int luaChon = -1;
	while (luaChon != 0) {
		system("cls");
		cout << "1 . Them sinh vien vao dau danh sach" << endl;
		cout << "2 . Them sinh vien vao cuoi danh sach" << endl;
		cout << "3 . Xoa sinh vien dau danh sach" << endl;
		cout << "4 . Xoa sinh vien cuoi danh sach" << endl;
		cout << "5 . Xuat danh sach sinh vien" << endl;
		cout << "6 . Xuat danh sach sinh vien xep loai yeu" << endl;
		cout << "7 . Xuat danh sach sinh vien co diem trung binh tren 5" << endl;
		cout << "8. Tim sinh vien theo ma sinh vien" << endl;
		cout << "9. Xoa toan bo sinh vien" << endl;
		cout << "10.Sap xep theo diem trung binh tang dan" << endl;
		cout << "11.Tim kiem sinh vien theo ten" << endl;
		cout << "0 . Ket thuc chuong trinh" << endl;
		cout << "Lua chon: ";
		cin >> luaChon;
		cin.ignore();
		switch (luaChon)
		{
		case 1: {
			SinhVien sv;
			sv.nhap();
			if (isMssv(ds.getHead(), sv.getMssv())) {
				cout << "Them that bai vi ma sinh vien da ton tai!" << endl;
				system("pause");
			}
			else {
				ds.themDau(sv);
				cout << "Them thanh cong" << endl;
				system("pause");
			}
 
			break;
		}
		case 2: {
			SinhVien sv;
			sv.nhap();
			if (isMssv(ds.getHead(), sv.getMssv())) {
				cout << "Them that bai vi ma sinh vien da ton tai!" << endl;
				system("pause");
			}
			else {
				ds.themCuoi(sv);
				cout << "Them thanh cong" << endl;
				system("pause");
			}
 
			break;
		}
		case 3: {
			ds.xoaDau();
			break;
		}
		case 4: {
			ds.xoaCuoi();
			break;
		}
		case 5: {
			ds.xuat();
			system("pause");
			break;
		}
		case 6: {
			ds.sinhVienXepLoaiYeu();
			system("pause");
			break;
		}
		case 7: {
			ds.sinhVienCoDTBTren5();
			system("pause");
			break;
		}
		case 8: {
			string mssv;
			cout << "Nhap ma sinh vien: ";
			cin >> mssv;
			ds.timSinhVienTheoMa(mssv);
			system("pause");
			break;
		}
		case 9: {
			ds.xoaToanBoDanhSach();
			break;
		}
		case 10: {
			ds.sapXepTheoDTBTangDan();
			break;
		}
		case 11: {
			string ten;
			cout << "Nhap sinh vien ten can tim: ";
			getline(cin, ten);
			ds.timKiemSinhVienTheoTen(ten);
			system("pause");
			break;
		}
		default:
			break;
		}
	}
	return 0;
}
