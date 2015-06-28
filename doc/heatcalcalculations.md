#Calculo da capacidade t�rmica de um dissipador de aluminio:

##requisitos:

- Conductividade t�rmica do material do dissipador
- volume do dissipador.
- Diferencial de temperatura dos meios em contacto

##introdu��o

A propriedade intrinseca dos materiais que nos permite compreender como funciona um sistema de arrefecimento. Esta compreens�o permite que em cen�rios complexos construir um sistema de arrefecimento mais ou menos eficiente, se utilizados os materiais correctos da forma correcta.

� necess�rio compreender que os detalhes ditam o sucesso ou o insucesso, n�o os ter em conta, reduz o desenho de sistemas de arrefecimento a uma mera adivinha��o.

Os sistemas de arrefecimento, obedecem a leis que se podem aproximar a sistemas hidra�licos na medida em que lidamos com quantidades, que tem de percorrer conductas s�lidas, com propriedades que definem fluxos, logo a n�o compreens�o destes fen�menos governadas por estas leis implica, a n�o realiza��o de sistemas eficientes.

posto isto, coloquemos o contexto da constru��o de um sistema de arrefecimento para um arrefecedor termoel�ctrico, baseado nos dispositivos TEC/Peltier que tiram partido do efeito de Sebbeck.

![Fotografia de um Peltier]()

O Peltier possui um lado quente e um lado frio, o primeiro dissipa o calor retirado do lado frio, criando um diferencial de temperatura, que pode atingir os 85 graus em determinados dispositivos.

A fun��o do dissipador de um sistema destes visa conduzir em primeiro lugar o calor gerado na superficie do Peltier at� ao ar que circunda o dispositivo. � priori parecer� simples, apenas temos de colocar um dissipador encostado ao peltier e obteremos a m�xima efici�ncia, nada mais errado, estariamos a abordar o problema de forma ing�nua e simplista, ao ponto de deixarmos de lado detalhes t�o importantes como: a superficie de contacto, peltier com o dispositivo a arrefecer, entre a superficie a arrefecer e o sensor, o contacto do lado quente do peltier com o dissipador.

Em primeiro lugar � necess�rio perceber que o ar se encontra na equa��o em determinados pontos de contacto, pois as superficies por mais polidas que sejam possuem uma rugosidade onde se encontrar� um isolante t�rmico dos mais eficientes, o ar. em segundo lugar se colocarmos um material que aumente a condu��o t�rmica, r�pidamente reduziremos a resist�ncia ao fluxo de calor. posteriormente, temos de compreender que um fluxo de ar no dissipador, deve ser suficiente para retirar o calor acumulado num dissipador por forma a aumentar a sua efici�ncia.

contemplemos o Dissipador no seu contacto com o ar, temos um material com um capacidade de condu��o t�rmica de aproximadamente 160 W. m-1 K-1, em contacto com um material, o ar, com uma capacidade de condu��o t�rmica, baixa, de 0.0262 W.m-1.K-1 logo um conductor t�rmico e uma fronteira para um isolante t�rmico, no entanto, � para este isolante t�rmico que temos que passar o calor. Para aumentar a efici�ncia desta transfer�cia de calor temos de aumentar a raz�o de transfer�ncia, e usualmente esse aumento obt�m-se aumentado a velocidade do fluxo de ar que permite retirar maior quantidade de calor. outra abordagem simples passa pelo aumento da superficie de contacto, que em hidr�ulica significaria o aumento da conduta de transfer�ncia, usualmente este concretiza��o obt�m com a mudan�a de um dissipador de laminas para um dissipador de pinos, ao duplicar a �rea do dissipador duplica-se a taxa de transfer�ncia de calor.

##Escolha do material do cold Finger:

A escolha do material do cold finger, foi realizada comparando os materiais dispon�veis, cobre e aluminio, se � priori pareceria que o aluminio se apresentaria como um bom candidato, r�pidamente ficou relegado para segundo lugar pela capacidade que possui de transmitir calor como se pode ver na tabela apresentada em 
[1].


Comparando a conductividade t�rmica de ambos se compreende que para o aluminio temos uma conductividade t�rmica de 249 W. m-1 Kelvin -1 e que para o Cobre temos um valor de 368 W.m-1.K-1, estando apenas a ter em linha de conta materiais puros, se pesquisarmos diferentes materiais dispon�veis no mercado, concluimos que dependendo do grau de pureza da liga disponivel para aquisi��o temos ainda piores valores de conductividade t�rmica. Mamt�m-se no entanto, o diferencial, ficando o cobre sempre na dianteira.

nesta compara��o apenas compreendemos ser o cobre o elemento de elei��o para a condu��o t�rmica do calor no caso do coldfinger, e no dissipador, no entanto a escolha deste elemento para o dissipador iria onerar muito os custos de produ��o de um dispositivo, como o que actualmente se encontra em desenvolvimento.


Compreender o Processo de transfer�ncia t�rmica e os factores que o influ�nciam:

Os factores que influ�nciam a transfer�ncia de calor s�o:

- Temperatura ambiente
- Humidade 
- Press�o Atmosf�rica.
- velocidade do Ar no dissipador
- Efici�ncia t�rmica do Peltier
- Efici�ncia t�rmica do conjunto de dissipa��o.


##Refer�ncias:

- [1] Listas de conductividades t�rmicas - https://en.wikipedia.org/wiki/List_of_thermal_conductivities
- Convers�o de Watt para Joule - http://www.rapidtables.com/convert/electric/Watt_to_Joule.htm
- Convers�od e Joule para Grau Celsius - http://www.convertunits.com/from/joule/to/celsius+heat+unit
- peltier Guide - http://www.heatsink-guide.com/peltier.htm
- Thermoelectric Cooling - https://en.wikipedia.org/wiki/Thermoelectric_cooling
- Thermal Design - http://www.smps.us/thermal.html
- Novel Concept Heat Sink CFD Simulations . http://www.novelconceptsinc.com/heat-sinks.htm



