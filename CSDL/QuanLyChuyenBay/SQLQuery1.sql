--C�u 1
select pc.MANV, pc.TEN, pc.DCHI, pc.DTHOAI
from NHANVIEN pc, PHANCONG p, LICHBAY lb
where pc.LOAINV = 1 and pc.MANV = p.MANV and p.MACB = lb.MACB and lb.MALOAI = 'B747'
--C�u 2
select lb.MACB, lb.NGAYDI
from LICHBAY lb, CHUYENBAY cb
where lb.MACB = cb.MACB and cb.SBDI = 'DCA' and cb.GIODI between '14:00' and '18:00'
--C�u 3
select distinct nv.TEN
from NHANVIEN nv, PHANCONG p, LICHBAY lb, CHUYENBAY cb
where nv.MANV = p.MANV and p.MACB = lb.MACB and lb.MACB = cb.MACB and cb.MACB = '100' and cb.SBDI = 'SLC' 
--C�u 4
select distinct lb.MALOAI, lb.SOHIEU
from LICHBAY lb, CHUYENBAY cb
where lb.MACB = cb.MACB and cb.SBDI = 'MIA'
--C�u 5
select distinct dc.MACB, dc.NGAYDI, kh.MAKH, kh.TEN, kh.DCHI, kh.DTHOAI
from DATCHO dc, KHACHHANG kh
where dc.MAKH = kh.MAKH
order by dc.MACB asc, dc.NGAYDI desc
--C�u 6
select distinct pc.MACB, pc.NGAYDI, nv.TEN, nv.DCHI, nv.DTHOAI
from NHANVIEN nv, PHANCONG pc
where nv.MANV = pc.MANV
order by pc.MACB asc, pc.NGAYDI desc
--C�u 7
select distinct p.MACB, p.NGAYDI,pc.MANV, pc.TEN 
from NHANVIEN pc, PHANCONG p, LICHBAY lb, CHUYENBAY cb
where pc.LOAINV = 1 and pc.MANV = p.MANV and p.MACB = lb.MACB and lb.MACB = cb.MACB and cb.SBDEN = 'ORD'
--C�u 8
select distinct p.MACB,p.NGAYDI, pc.TEN
from NHANVIEN pc, PHANCONG p
where pc.MANV = p.MANV and pc.MANV = '1001'
--C�u 9
select distinct cb.MACB, cb.SBDI, cb.GIODI, cb.GIODEN, lb.NGAYDI
from LICHBAY lb, CHUYENBAY cb
where lb.MACB = cb.MACB and cb.SBDEN = 'DEN'
order by lb.NGAYDI desc, cb.SBDI asc
--C�u 10
select distinct pc.TEN, lmb.HANGSX, lmb.MALOAI
from NHANVIEN pc, KHANANG kn, LOAIMB lmb
where pc.LOAINV = 1 and pc.MANV = kn.MANV and kn.MALOAI = lmb.MALOAI
--C�u 11
select distinct pc.MANV, pc.TEN
from NHANVIEN pc, PHANCONG p, LICHBAY lb
where pc.LOAINV = 1 and pc.MANV = p.MANV and p.MACB = lb.MACB and lb.MACB = '100' and lb.NGAYDI = '11/01/2000'
--C�u 12
select distinct cb.MACB, pc.MANV, pc.TEN
from NHANVIEN pc, PHANCONG p, LICHBAY lb, CHUYENBAY cb
where pc.LOAINV = 1 and pc.MANV = p.MANV and p.MACB = lb.MACB and lb.MACB = cb.MACB and lb.NGAYDI = '10/31/2000' and cb.SBDI = 'MIA' and cb.GIODI = '20:30' 
--C�u 13
select distinct lb.MACB, lb.SOHIEU,lb.MALOAI, lmb.HANGSX
from NHANVIEN pc, PHANCONG p, LICHBAY lb, LOAIMB lmb
where pc.TEN = 'Quang' and pc.MANV = p.MANV and p.MACB = lb.MACB and lb.MALOAI = lmb.MALOAI 
--C�u 14
select distinct pc.TEN
from NHANVIEN pc
where pc.LOAINV = 1 and pc.MANV not in (select pc1.MANV
                                        from NHANVIEN pc1, PHANCONG p
										where pc1.LOAINV = 1 and pc1.MANV = p.MANV)
--C�u 15
select distinct kh.TEN
from KHACHHANG kh, DATCHO dc, LICHBAY lb, LOAIMB lmb
where kh.MAKH = dc.MAKH and dc.MACB = lb.MACB and lb.MALOAI = lmb.MALOAI and lmb.HANGSX = 'Boeing'
--C�u 16
select distinct lb.MACB
from LICHBAY lb
where lb.SOHIEU = '10' and lb.MALOAI = 'B747'