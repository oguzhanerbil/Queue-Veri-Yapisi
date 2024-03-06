# Kuyruk Veri Yapıları

## Kuyruk Veri Yapıları Nedir ?

Kuyruk veri yapıları, verilerin düzenli bir şekilde saklandığı ve işlendiği bir koleksiyon tipidir. Adından da anlaşılacağı gibi, bir kuyruk veri yapısı, gerçek hayattaki bir kuyruğa benzer şekilde işler: ilk giren ilk çıkar (FIFO - First In, First Out) prensibi ile çalışır. Bu, veri yapılarına eklenen ilk öğenin, çıkarılan ilk öğe olduğu anlamına gelir. Kuyruk yapıları, birçok farklı uygulamada kullanılır, özellikle işlem sırasını korumak, veri akışını yönetmek ve asenkron işlemlerde verileri sıraya koymak gibi durumlarda vazgeçilmezdirler.

## Kuyruk Veri Yapılarının Temel Özellikleri
* FIFO Prensibi: Kuyruk veri yapıları, ilk giren ilk çıkar prensibine göre hareket eder. Bu, koleksiyona ilk eklenen öğenin, koleksiyondan ilk çıkarılan öğe olacağı anlamına gelir.
* Enqueue Operasyonu: Bir kuyruğa yeni bir öğe eklemek için kullanılır. Ekleme işlemi, kuyruğun sonuna yapılır.
* Dequeue Operasyonu: Kuyruktan bir öğe çıkarmak için kullanılır. Çıkarma işlemi, kuyruğun başından yapılır ve kuyruğa ilk eklenen öğeyi kaldırır.
Peek/ Front Operasyonu: Kuyruğun başındaki öğeyi silmeden döndürür. Bu, kuyruğun en önündeki öğeyi incelemek için kullanılır.
##Kuyruk Veri Yapıları Nerede Kullanılır?
### Kuyruk veri yapıları, birçok farklı alan ve uygulamada kullanılır. İşte bazı örnekler:

* İşletim Sistemleri: İşletim sistemleri, işlemlerin yönetimi ve planlanması için kuyruk yapılarını kullanır. Bu, işlemlerin adil bir şekilde ve belirli bir sırayla işlenmesini sağlar.
* Ağ Trafiği Yönetimi: Ağ cihazları, gelen veri paketlerini işlemek için kuyruk yapılarını kullanır. Bu, paketlerin düzgün bir sıra ile işlenmesini ve iletilmesini sağlar.
* Yazılım Uygulamaları: Asenkron işlemler, olay yönetimi ve veri akışı kontrolü gibi durumlar için yazılım uygulamaları sıkça kuyruk yapılarını tercih eder.
