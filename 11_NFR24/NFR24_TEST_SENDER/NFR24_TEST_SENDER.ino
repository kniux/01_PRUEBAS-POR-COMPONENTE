/*************************************************************
           nRF24L01 Arduino发送端
           引脚接法：
           nRF24L01   Arduino UNO
            VCC  <-> 3.3V
            GND <-> GND
            CE  <-> D9
            CSN <-> D10
            MOSI<-> D11
            MISO<-> D12
            SCK <-> D13
            IRQ <-> 不接
***************************************************************/
#include <SPI.h>
#include <Mirf.h>
#include <Mirf_nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
#define BAUD_RATE 9600
void setup()
{
    Serial.begin(BAUD_RATE);

    Mirf.cePin = 9;   //设置CE引脚为D9
    Mirf.csnPin = 10; //设置CE（片选引脚）引脚为D10
    Mirf.spi = &MirfHardwareSpi;
    Mirf.init();  //初始化nRF24L01   

  //设置接收标识符"Rec01"
    Mirf.setRADDR((byte *)"Rec01");
    //设置一次收发的字节数，这里发一个整数，写sizeof(unsigned int)，实际等于2字节
    //Payload width in bytes default 16 max 32.
    Mirf.payload = sizeof(unsigned int);
    //发送通道定义，收发必须一致。
    //Channel 0 - 127 or 0 - 84 in the US.
    Mirf.channel = 3;
    Mirf.config();

  //注意一个Arduino写Sender.ino，另一个写Receiver.ino。
  //这里标识写入了Sender.ino
    Serial.println("I'm Sender...");
}
unsigned int adata = 0;
void loop()
{
  //读取A0值到adata
    adata = analogRead(A0);

    //由于nRF24L01只能以byte单字节数组形式发送Mirf.payload个数据，
    //所以必须将所有需要传输的数据拆成byte。
    //下面定义byte数组，存放待发数据，因为Mirf.payload = sizeof(unsigned int);
    //实际下面等于byte data[2];
    byte data[Mirf.payload];

    //adata是unsigned int双字节数据，必须拆开。
    //将adata高低八位拆分：
    data[0] = adata & 0xFF;   //低八位给data[0]，
    data[1] = adata >> 8;   //高八位给data[1]。
   
    
    //向"Rec01"发送数据
    Mirf.send(data);
    //while死循环等待发送完毕，才能进行下一步操作。
    //isSending()会读取发送端24l01芯片内部寄存器，判断是否发送完毕，如果发送完毕true，退出循环
    while(Mirf.isSending()) {}
    delay(20);
}
