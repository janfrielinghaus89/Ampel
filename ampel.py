import time

ampel = ["Grün", "Gelb", "Rot"]
stromnetz = True
knopfsignal = False
ampelfarbe = ampel[0]
wartezeit = "Wartezeit von 3 Sekunden"

def signalschaltung():
    print(wartezeit)
    time.sleep(3)
    ampelfarbe = ampel[1]
    print("Ampel schaltet " + ampelfarbe)
    print(wartezeit)
    time.sleep(3)
    ampelfarbe = ampel[2]
    print("Ampel schaltet " + ampelfarbe)
    print(wartezeit)
    time.sleep(3)

def signalrueckschaltung():
    ampelfarbe = ampel[1]
    print("Ampel schaltet " + ampelfarbe)
    print(wartezeit)
    time.sleep(3)
    ampelfarbe = ampel[0]
    print("Ampel schaltet " + ampelfarbe)

def knopf_druck():
    print("### Knopf wird gedrückt ###")
    return True
    
#########################################
# Ampel verändert sich durch Knopfdruck #
#########################################
knopfsignal = knopf_druck()

while stromnetz and ampelfarbe == ampel[0]:
    if knopfsignal:
        signalschaltung()
        signalrueckschaltung()
        knopfsignal = False
