#1
x <- c(1, 2, 3, 4, 5, 6, 7) #zmienna niezale¿na, dzieñ obserwacji
y <- c(2, 3, 5, 7, 10, 14, 26) #zmienna zale¿na, procent zara¿onych

plot(x, y)


#a)
model1 <- lm(y~x) # Y = a + b*X
model2 <- lm(log(y)~x) # log(Y) = a + b*X

# wspó³czynniki determinacji R^2 dla tych modeli:
summary(model1)$r.squared #0.8379788
summary(model2)$r.squared #0.9933263 < wybieram model2, poniewa¿ R^2 jest bardzo blisko 1

#b)
summary(model2)
#1) Czy istnieje zale¿noœæ pomiêdzy Y a X?
#H0: b = 0 (NIE)
#H1: b != 0 (TAK)
#p-value: 1.24e-06=1.24*10^-6 < 5%
#czyli wybieram H1, jest zale¿noœæ

#2) Czy wyraz wolny jest istotny w modelu?
#H0: a = 0 (NIE)
#H1: a != 0 (TAK)
# p-value: 0.00689 < 5%
#czyli H1, jest istotny

#wspó³czynnik determinacji R^2 = 0.9933, bardzo blisko 1, czyli dobrze dopasowany do danych

reszty <- model2$residuals
#za³o¿enie o normalnoœci reszt
shapiro.test(reszty) #p-value = 0.6804>5%, czyli spe³nione
#za³o¿enie o zerowej œredniej reszt
t.test(reszty, mu=0) #p-value = 1>5%, spe³nione
#za³o¿enie o losowoœci reszt
plot(reszty) #widaæ chmurê punktów, spe³nione

#c)
exp(predict(model2, list(x=9), level = 0.95, interval = 'p'))
# fit     lwr      upr
# 53.69281 40.1203 71.85683
#czyli mamy 95% pewnoœci, ¿e w dniu 8 bêdzie zara¿onych pomiêdzy 40, a 71 zwierz¹t
#a na linii modelu 53 zwierzêta








#2
data(airquality)
airquality=na.omit(airquality)

x <- c(airquality$Ozone)
czynnikA <- factor(airquality$Month, levels = c(5, 6, 7, 8, 9), labels = c('Maj','Czerwiec','Lipiec', 'Sierpien', 'Wrzesien'))
#Czy œredni poziom ozonu znacz¹co ró¿ni siê w tych miesi¹cach?
#H0: µ5 = µ6 = µ7 = µ8 = µ9, ró¿ni¹ siê istotnie
#H1: ¬H0, nie ró¿ni¹ siê istotnie

#Weryfikacja za³o¿eñ ANOVA
#1. Czy czy wariancje ró¿ni¹ siê istotnie?
bartlett.test(x~czynnikA) #p-value = 0.007395 < 5%, ró¿ni¹ siê istotnie
#2. Czy próbki maj¹ rozk³ady normalne?
tapply(x, czynnikA, shapiro.test)
#Maj p-value = 1.491e-05 <5%, nie ma rozk³adu normalnego
#Czerwiec p-value = 0.0628
#Lipiec p-value = 0.8669
#Sierpien p-value = 0.08751
#Wrzesien p-value = 4.325e-05 <5%, nie ma rozk³adu normalnego

#poniewa¿ za³o¿enia nie s¹ spe³nione u¿ywam testu Kruskala-Wallisa
kruskal.test(x~czynnikA) #p-value = 2.742e-05 <5%
#czyli wybieram H1, mogê stwierdziæ, ¿e w tych miesi¹cach œrednia iloœæ ozonu ró¿ni siê istotnie

#3
x <- c(100, 120, 200, 250, 300, 280, 350) #zmienna niezale¿na, wielkoœæ dawki
y <- c(4.9, 4.9, 7.5, 8.9, 9.8, 9.5, 11.5) #zmienna zale¿na, przyrost wagi

#a)
plot(x, y)
cor(x, y) #0.9963291
#Mo¿emy zauwa¿yæ, ¿e zale¿noœæ miêdzy danymi jest silna

#b)
lm(y~x)#Y =  0.02687*X + 2.00165
abline(lm(y~x), col=2, lwd=2)

#c)
model <- lm(y~x)
summary(model)
#1) Czy istnieje zale¿noœæ pomiêdzy Y a X?
#H0: b = 0 (NIE)
#H1: b != 0 (TAK)
#p-value: 1.57e-06=1.57*10^-6 < 5%
#czyli wybieram H1, jest zale¿noœæ

#2) Czy wyraz wolny jest istotny w modelu?
#H0: a = 0 (NIE)
#H1: a != 0 (TAK)
# p-value: 0.000512 < 5%
#czyli H1, jest istotny

#wspó³czynnik determinacji R^2 = 0.9927, bardzo blisko 1, czyli dobrze dopasowany do danych

reszty <- model$residuals
#za³o¿enie o normalnoœci reszt
shapiro.test(reszty) #p-value = 0.171>5%, czyli spe³nione
#za³o¿enie o zerowej œredniej reszt
t.test(reszty, mu=0) #p-value = 1>5%, spe³nione
#za³o¿enie o losowoœci reszt
plot(reszty) #widaæ chmurê punktów, spe³nione

#d)
predict(model, list(x=220), level = 0.99, interval = 'p')
# fit      lwr      upr
# 7.912562 6.896301 8.928823
#czyli mamy 99% pewnoœci, ¿e przy dawce 220mg przyrost masy wyniesie miêdzy 6.896, a 8.929
#a dok³adnie na linii modelu 7.912