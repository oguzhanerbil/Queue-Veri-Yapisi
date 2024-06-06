using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KitapKurdu
{
    public class Kitap
    {
        public string Baslik { get; set; }
        public Yazar Yazar { get; set; }
        public bool OduncAlinan { get; set; }
        public int KitapNumarasi { get; set; }

        public Kitap(string baslik, Yazar yazar, bool oduncAlinan, int kitapNumarasi)
        {
            Baslik = baslik;
            Yazar = yazar;
            OduncAlinan = oduncAlinan;
            KitapNumarasi = kitapNumarasi;
        }

        public void Yazdir()
        {
            Console.WriteLine($"Başlık: {Baslik}, Yazar: {Yazar.Isim}, Ödünç Alınmış: {OduncAlinan}, Kitap Numarası: {KitapNumarasi}");
        }

        public void OduncAlinmis()
        {
            OduncAlinan = true;
        }

        public void IadeEdilmis()
        {
            OduncAlinan = false;
        }
    }

    public class Yazar
    {
        public string Isim { get; set; }
        public string Eposta { get; set; }

        public Yazar(string isim, string eposta)
        {
            Isim = isim;
            Eposta = eposta;
        }

        public bool EpostaGuncelle(string yeniEposta)
        {
            Eposta = yeniEposta;
            return true;
        }

        public void Yazdir()
        {
            Console.WriteLine($"Yazar: {Isim}, E-posta: {Eposta}");
        }
    }

    public class Kutuphane
    {
        public Kitap[] Kitaplar { get; private set; } = new Kitap[10];
        public string KutuphaneSaatleri { get; set; } = "09:00 - 17:00";
        public string Adres { get; set; }
        private int kitapSayisi = 0;

        public Kutuphane(string adres)
        {
            Adres = adres;
        }

        public void EkleKitap(Kitap kitap)
        {
            if (kitapSayisi < 10)
            {
                Kitaplar[kitapSayisi] = kitap;
                kitapSayisi++;
            }
            else
            {
                Console.WriteLine("Kütüphane dolu.");
            }
        }

        public void SaatleriYazdir()
        {
            Console.WriteLine($"Kütüphane Saatleri: {KutuphaneSaatleri}");
        }

        public void AdresYazdir()
        {
            Console.WriteLine($"Adres: {Adres}");
        }

        public void YazdirKitaplari()
        {
            foreach (var kitap in Kitaplar)
            {
                if (kitap != null)
                {
                    kitap.Yazdir();
                }
            }
        }

        public bool OduncAl(string kitapAdi)
        {
            foreach (var kitap in Kitaplar)
            {
                if (kitap != null && kitap.Baslik == kitapAdi)
                {
                    if (kitap.OduncAlinan)
                    {
                        Console.WriteLine("Kitap zaten ödünç alınmış.");
                        return false;
                    }
                    else
                    {
                        kitap.OduncAlinmis();
                        Console.WriteLine($"Kitap ödünç alındı: {kitapAdi}");
                        return true;
                    }
                }
            }
            Console.WriteLine("Kitap bulunamadı.");
            return false;
        }

        public bool IadeEt(string kitapAdi)
        {
            foreach (var kitap in Kitaplar)
            {
                if (kitap != null && kitap.Baslik == kitapAdi)
                {
                    if (!kitap.OduncAlinan)
                    {
                        Console.WriteLine("Kitap zaten iade edilmiş.");
                        return false;
                    }
                    else
                    {
                        kitap.IadeEdilmis();
                        Console.WriteLine($"Kitap iade edildi: {kitapAdi}");
                        return true;
                    }
                }
            }
            Console.WriteLine("Kitap bulunamadı.");
            return false;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // Yazarlar
            Yazar yazar1 = new Yazar("Yazar 1", "yazar1@example.com");
            Yazar yazar2 = new Yazar("Yazar 2", "yazar2@example.com");

            // Kitaplar
            Kitap kitap1 = new Kitap("Kitap 1", yazar1, false, 1);
            Kitap kitap2 = new Kitap("Kitap 2", yazar2, false, 2);
            Kitap kitap3 = new Kitap("Kitap 3", yazar1, false, 3);
            Kitap kitap4 = new Kitap("Kitap 4", yazar2, false, 4);

            // Kütüphaneler
            Kutuphane kutuphane1 = new Kutuphane("Adres 1");
            Kutuphane kutuphane2 = new Kutuphane("Adres 2");

            // Kitapları ekleme
            kutuphane1.EkleKitap(kitap1);
            kutuphane1.EkleKitap(kitap2);
            kutuphane2.EkleKitap(kitap3);
            kutuphane2.EkleKitap(kitap4);

            // Kütüphane bilgileri yazdırma
            kutuphane1.SaatleriYazdir();
            kutuphane1.AdresYazdir();
            kutuphane1.YazdirKitaplari();

            kutuphane2.SaatleriYazdir();
            kutuphane2.AdresYazdir();
            kutuphane2.YazdirKitaplari();

            // Kitap ödünç alma ve iade etme
            kutuphane1.OduncAl("Kitap 1");
            kutuphane1.OduncAl("Kitap 2");

            kutuphane1.YazdirKitaplari();

            kutuphane1.IadeEt("Kitap 1");
            kutuphane1.IadeEt("Kitap 2");

            kutuphane1.YazdirKitaplari();
            Console.ReadKey();      
        }
    }
}
