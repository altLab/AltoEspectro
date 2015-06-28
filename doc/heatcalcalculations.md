

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

O Peltier possui um Lado quente e um lado frio, o primeiro dissipa o calor retirado do lado frio, criando um diferencial de temperatura, que pode atingir os 85 graus em determinados contextos.

A função do dissipador de um sistema destes visa conduzir em primeiro lugar o calor gerado na superficie do Peltier até ao ar que circunda o dispositivo. À priori parecerá simples, apenas temos de colocar um dissipador encostado ao peltier e obteremos a máxima eficiência, nada mais errado, estariamos a abordar o problema de forma ingénua e simplista, ao ponto de deixarmos de lado detalhes tão importantes como: a superficie de contacto, peltier com o dispositivo a arrefecer, entre a superficie a arrefecer e o sensor, o contacto do lado quente do peltier com o dissipador.

Em primeiro lugar é necessário perceber que o ar se encontra na equação em determinados pontos de contacto, pois as superficies por mais polidas que sejam possuem uma rugosidade onde se encontrará um isolante térmico, o ar. em segundo lugar se colocarmos um material que aumente a condução térmica, rápidamente reduziremos a resistência ao fluxo de calor. posteriormente, temos de compreender que um fluxo de ar no dissipador, deve ser suficiente para retirar o calor acumulado num dissipador por forma a aumentar a sua do dissipador eficiência.

contemplemos o Dissipador no seu contacto com o ar, temos um material com um capacidade de condução térmica, em contacto com um material, o ar, com uma capacidade de condução térmica, baixa, logo um conductor térmico e uma fronteira para um isolante térmico, no entanto, é para este isolante térmico que temos que passar o calor.

##Escolha do material do cold Finger:

A escolha do material do cold finger, foi realizada comparando os materiais disponíveis, cobre e aluminio, se à priori pareceria que o aluminio se apresentaria como um bom candidato, rápidamente ficou relegado para segundo lugar pela capacidade que possui de transmitir calor como se pode ver na tabela apresentada em [1].

Comparando a conductividade térmica de ambos se compreende que para o aluminio temos uma conductividade térmica de 249 W. m-1 Kelvin -1 e que para o Cobre temos um valor de 368 W.m-1.K-1, estando apenas a ter em linha de conta materiais puros, se pesquisarmos diferentes materiais disponíveis no mercado, concluimos que dependendo do grau de pureza da liga disponivel para aquisição temos ainda piores valores de conductividade térmica.

nesta comparação apenas compreendemos ser o cobre o elemento de eleição para a condução térmica do calor no caso do coldfinger, e no dissipador, no entanto a escolha deste elemento para o dissipador iria onerar muito os custos de produção de um dispositivo, como o que actualmente se encontra em desenvolvimento.


##Calculos:

Peltier a funcionar a 5V consumindo 0,6A Consume a potência de 3W.

Logo um peltier a funcionar a 3W durante um minuto = 60 segundos produz um trabalho de 180 Joule.

será necesário então determinar também a eficiência do Peltier na conversãod e calor do lado frio para o lado quente.

uma vez determina a temepratura do lado quente será então necessário determinar a capacidade do dissipador em retirar esse calor sem a assistência de uma corrente forçada de arrefecimento.

A eficiência de um dissipador é também função da temperatura ambiente pois pode aumentar ou reduzir a capacidade do mesmo em retirar calor.

outro elemento fundamental na compreensão da eficiência de um dissipador/irradiador é a quantidade de humidade relativa no ar, assim como a pressão atmosférica no momento da realização do trabalho. pois estes parãmetros influênciam de modo concreto os resultados, fazendo com que o design da capacidade de arrefecimento de um peltier tenham de ser desenhadas para um cenário desfavorável por forma a ser possível realizar o trabalho nas condições mais variadas, dentro de certos limites.






##Referências:

- [1] Listas de conductividades térmicas - https://en.wikipedia.org/wiki/List_of_thermal_conductivities
- Conversão de Watt para Joule - http://www.rapidtables.com/convert/electric/Watt_to_Joule.htm
- Conversãod e Joule para Grau Celsius - http://www.convertunits.com/from/joule/to/celsius+heat+unit
