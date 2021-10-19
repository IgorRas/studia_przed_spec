#1
x <- c(1, 2, 3, 4, 5, 6, 7) #zmienna niezależna, dzień obserwacji
y <- c(2, 3, 5, 7, 10, 14, 26) #zmienna zależna, procent zarażonych

plot(x, y)


#a)
model1 <- lm(y~x) # Y = a + b*X
model2 <- lm(log(y)~x) # log(Y) = a + b*X

# współczynniki determinacji R^2 dla tych modeli:
summary(model1)$r.squared #0.8379788
summary(model2)$r.squared #0.9933263 < wybieram model2, ponieważ R^2 jest bardzo blisko 1

#b)
summary(model2)
#1) Czy istnieje zależność pomiędzy Y a X?
#H0: b = 0 (NIE)
#H1: b != 0 (TAK)
#p-value: 1.24e-06=1.24*10^-6 < 5%
#czyli wybieram H1, jest zależność

#2) Czy wyraz wolny jest istotny w modelu?
#H0: a = 0 (NIE)
#H1: a != 0 (TAK)
# p-value: 0.00689 < 5%
#czyli H1, jest istotny

#współczynnik determinacji R^2 = 0.9933, bardzo blisko 1, czyli dobrze dopasowany do danych

reszty <- model2$residuals
#założenie o normalności reszt
shapiro.test(reszty) #p-value = 0.6804>5%, czyli spełnione
#założenie o zerowej średniej reszt
t.test(reszty, mu=0) #p-value = 1>5%, spełnione
#założenie o losowości reszt
plot(reszty) #widać chmurę punktów, spełnione

#c)
exp(predict(model2, list(x=9), level = 0.95, interval = 'p'))
# fit     lwr      upr
# 53.69281 40.1203 71.85683
#czyli mamy 95% pewności, że w dniu 8 będzie zarażonych pomiędzy 40, a 71 zwierząt
#a na linii modelu 53 zwierzęta








#2
data(airquality)
airquality=na.omit(airquality)

x <- c(airquality$Ozone)
czynnikA <- factor(airquality$Month, levels = c(5, 6, 7, 8, 9), labels = c('Maj','Czerwiec','Lipiec', 'Sierpien', 'Wrzesien'))
#Czy średni poziom ozonu znacząco różni się w tych miesiącach?
#H0: µ5 = µ6 = µ7 = µ8 = µ9, różnią się istotnie
#H1: ¬H0, nie różnią się istotnie

#Weryfikacja założeń ANOVA
#1. Czy czy wariancje różnią się istotnie?
bartlett.test(x~czynnikA) #p-value = 0.007395 < 5%, różnią się istotnie
#2. Czy próbki mają rozkłady normalne?
tapply(x, czynnikA, shapiro.test)
#Maj p-value = 1.491e-05 <5%, nie ma rozkładu normalnego
#Czerwiec p-value = 0.0628
#Lipiec p-value = 0.8669
#Sierpien p-value = 0.08751
#Wrzesien p-value = 4.325e-05 <5%, nie ma rozkładu normalnego

#ponieważ założenia nie są spełnione używam testu Kruskala-Wallisa
kruskal.test(x~czynnikA) #p-value = 2.742e-05 <5%
#czyli wybieram H1, mogę stwierdzić, że w tych miesiącach średnia ilość ozonu różni się istotnie

#3
x <- c(100, 120, 200, 250, 300, 280, 350) #zmienna niezależna, wielkość dawki
y <- c(4.9, 4.9, 7.5, 8.9, 9.8, 9.5, 11.5) #zmienna zależna, przyrost wagi

#a)
plot(x, y)
cor(x, y) #0.9963291
#Możemy zauważyć, że zależność między danymi jest silna

#b)
lm(y~x)#Y =  0.02687*X + 2.00165
abline(lm(y~x), col=2, lwd=2)

#c)
model <- lm(y~x)
summary(model)
#1) Czy istnieje zależność pomiędzy Y a X?
#H0: b = 0 (NIE)
#H1: b != 0 (TAK)
#p-value: 1.57e-06=1.57*10^-6 < 5%
#czyli wybieram H1, jest zależność

#2) Czy wyraz wolny jest istotny w modelu?
#H0: a = 0 (NIE)
#H1: a != 0 (TAK)
# p-value: 0.000512 < 5%
#czyli H1, jest istotny

#współczynnik determinacji R^2 = 0.9927, bardzo blisko 1, czyli dobrze dopasowany do danych

reszty <- model$residuals
#założenie o normalności reszt
shapiro.test(reszty) #p-value = 0.171>5%, czyli spełnione
#założenie o zerowej średniej reszt
t.test(reszty, mu=0) #p-value = 1>5%, spełnione
#założenie o losowości reszt
plot(reszty) #widać chmurę punktów, spełnione

#d)
predict(model, list(x=220), level = 0.99, interval = 'p')
# fit      lwr      upr
# 7.912562 6.896301 8.928823
#czyli mamy 99% pewności, że przy dawce 220mg przyrost masy wyniesie między 6.896, a 8.929
#a dokładnie na linii modelu 7.912
