#Calculo da capacidade térmica de um dissipador de aluminio:

##requisitos:

- Conductividade térmica do material do dissipador
- volume do dissipador.
- Diferencial de temperatura dos meios em contacto

##introdução

A propriedade intrinseca dos materiais que nos permite compreender como funciona um sistema de arrefecimento. Esta compreensão permite que em cenários complexos construir um sistema de arrefecimento mais ou menos eficiente, se utilizados os materiais correctos da forma correcta.

É necessário compreender que os detalhes ditam o sucesso ou o insucesso, não os ter em conta, reduz o desenho de sistemas de arrefecimento a uma mera adivinhação.

Os sistemas de arrefecimento, obedecem a leis que se podem aproximar a sistemas hidraúlicos na medida em que lidamos com quantidades, que tem de percorrer conductas sólidas, com propriedades que definem fluxos, logo a não compreensão destes fenómenos governadas por estas leis implica, a não realização de sistemas eficientes.

posto isto, coloquemos o contexto da construção de um sistema de arrefecimento para um arrefecedor termoeléctrico, baseado nos dispositivos TEC/Peltier que tiram partido do efeito de Sebbeck.

![Fotografia de um Peltier]()

O Peltier possui um lado quente e um lado frio, o primeiro dissipa o calor retirado do lado frio, criando um diferencial de temperatura, que pode atingir os 85 graus em determinados dispositivos.

A função do dissipador de um sistema destes visa conduzir em primeiro lugar o calor gerado na superficie do Peltier até ao ar que circunda o dispositivo. À priori parecerá simples, apenas temos de colocar um dissipador encostado ao peltier e obteremos a máxima eficiência, nada mais errado, estariamos a abordar o problema de forma ingénua e simplista, ao ponto de deixarmos de lado detalhes tão importantes como: a superficie de contacto, peltier com o dispositivo a arrefecer, entre a superficie a arrefecer e o sensor, o contacto do lado quente do peltier com o dissipador.

Em primeiro lugar é necessário perceber que o ar se encontra na equação em determinados pontos de contacto, pois as superficies por mais polidas que sejam possuem uma rugosidade onde se encontrará um isolante térmico dos mais eficientes, o ar. em segundo lugar se colocarmos um material que aumente a condução térmica, rápidamente reduziremos a resistência ao fluxo de calor. posteriormente, temos de compreender que um fluxo de ar no dissipador, deve ser suficiente para retirar o calor acumulado num dissipador por forma a aumentar a sua eficiência.

contemplemos o Dissipador no seu contacto com o ar, temos um material com um capacidade de condução térmica de aproximadamente 160 W. m-1 K-1, em contacto com um material, o ar, com uma capacidade de condução térmica, baixa, de 0.0262 W.m-1.K-1 logo um conductor térmico e uma fronteira para um isolante térmico, no entanto, é para este isolante térmico que temos que passar o calor. Para aumentar a eficiência desta transferêcia de calor temos de aumentar a razão de transferência, e usualmente esse aumento obtém-se aumentado a velocidade do fluxo de ar que permite retirar maior quantidade de calor. outra abordagem simples passa pelo aumento da superficie de contacto, que em hidráulica significaria o aumento da conduta de transferência, usualmente este concretização obtém com a mudança de um dissipador de laminas para um dissipador de pinos, ao duplicar a área do dissipador duplica-se a taxa de transferência de calor.

##Escolha do material do cold Finger:

A escolha do material do cold finger, foi realizada comparando os materiais disponíveis, cobre e aluminio, se à priori pareceria que o aluminio se apresentaria como um bom candidato, rápidamente ficou relegado para segundo lugar pela capacidade que possui de transmitir calor como se pode ver na tabela apresentada em 
[1].


Comparando a conductividade térmica de ambos se compreende que para o aluminio temos uma conductividade térmica de 249 W. m-1 Kelvin -1 e que para o Cobre temos um valor de 368 W.m-1.K-1, estando apenas a ter em linha de conta materiais puros, se pesquisarmos diferentes materiais disponíveis no mercado, concluimos que dependendo do grau de pureza da liga disponivel para aquisição temos ainda piores valores de conductividade térmica. Mamtém-se no entanto, o diferencial, ficando o cobre sempre na dianteira.

nesta comparação apenas compreendemos ser o cobre o elemento de eleição para a condução térmica do calor no caso do coldfinger, e no dissipador, no entanto a escolha deste elemento para o dissipador iria onerar muito os custos de produção de um dispositivo, como o que actualmente se encontra em desenvolvimento.


Compreender o Processo de transferência térmica e os factores que o influênciam:

Os factores que influênciam a transferência de calor são:

- Temperatura ambiente
- Humidade 
- Pressão Atmosférica.
- velocidade do Ar no dissipador
- Eficiência térmica do Peltier
- Eficiência térmica do conjunto de dissipação.


##Referências:

- [1] Listas de conductividades térmicas - https://en.wikipedia.org/wiki/List_of_thermal_conductivities
- Conversão de Watt para Joule - http://www.rapidtables.com/convert/electric/Watt_to_Joule.htm
- Conversãod e Joule para Grau Celsius - http://www.convertunits.com/from/joule/to/celsius+heat+unit
- peltier Guide - http://www.heatsink-guide.com/peltier.htm
- Thermoelectric Cooling - https://en.wikipedia.org/wiki/Thermoelectric_cooling
- Thermal Design - http://www.smps.us/thermal.html
- Novel Concept Heat Sink CFD Simulations . http://www.novelconceptsinc.com/heat-sinks.htm



