import time
import random
import threading


class Bucket:

    def __init__(self, bucket_size=512, link_speed=1):
        self.bucket_size = bucket_size
        self.link_speed = link_speed
        self.remaining_size = self.bucket_size
        self.queue = list()
        self.overflow = False

    def input(self, packet_size, packet_number):
        if packet_size > self.remaining_size:
            print("Bucket Overflow.")
            self.overflow = True
            return False
        else:
            self.remaining_size -= packet_size
            self.queue.append((packet_size, packet_number))
            return True

    def output(self):
        while True:
            if self.queue != list():
                packet_size, packet_number = self.queue.pop(0)
                while packet_size > self.link_speed:
                    print("Output Packet", str(packet_number) +
                          ":", self.link_speed, "Bytes")
                    self.remaining_size += self.link_speed
                    packet_size -= self.link_speed
                    time.sleep(1)
                if packet_size > 0 and packet_size < self.link_speed:
                    print("Last Output Packet", str(
                        packet_number) + ":", packet_size, "Bytes")
                    self.remaining_size += packet_size
                    time.sleep(1)
            else:
                if self.overflow:
                    return


bucket_size = int(input("Enter bucket size: "))
link_speed = int(input("Enter link speed (Bps): "))
bucket = Bucket(bucket_size=bucket_size, link_speed=link_speed)
bucket_thread = threading.Thread(target=bucket.output)
bucket_thread.start()

packet_size = random.randint(1, int(bucket_size))
packet_number = 0
while bucket.input(packet_size, packet_number):
    print("Input Packet", str(packet_number) + ":", packet_size, "Bytes")
    time.sleep(1)
    packet_size = random.randint(1, int(bucket_size))
    packet_number += 1
