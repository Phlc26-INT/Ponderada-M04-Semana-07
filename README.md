# Ponderada Semana 07 M04 - Sensor de Intensidade WiFi com ESP32 e Dashboard Ubidots

## Descrição do Projeto

Este projeto IoT implementa um sistema de monitoramento da intensidade do sinal WiFi utilizando um ESP32. O sistema coleta dados de potência do sinal em dBm e os transmite via protocolo MQTT para uma plataforma online (Ubidots), onde são visualizados em tempo real através de um dashboard interativo.

### Objetivos

- Monitorar continuamente a intensidade do sinal WiFi em dBm
- Aprendizado sobre a transmissão dados em tempo real via MQTT
- Visualizar os dados em dashboard online
- Demonstrar o efeito da "Gaiola de Faraday" 

## Componentes Utilizados

### Hardware Utilizado
- **ESP32** 
- **Antena básica** 

## Como Funciona

### Fluxo de Dados
1. **Coleta**: ESP32 mede RSSI da rede WiFi conectada
2. **Processamento**: Converte o valor para dBm
3. **Transmissão**: Envia via MQTT para Ubidots a cada 3 segundos
4. **Visualização**: Dashboard exibe gráfico tempo x dBm em tempo real

### Documentação em Vídeo
- **Duração**: ~ 4 minutos
- **Conteúdo**: Gravação do dashboard + serial monitor com descrição e explicações
- **Upload**: [Vídeo no Google Drive](https://drive.google.com/file/d/1m1wZpys7fEMZ5LqIBMmS36Ikl9xrXwUv/view?usp=sharing)

## Interpretação dos Resultados

### Valores Típicos de RSSI
- **-30 a -50 dBm**: Excelente
- **-50 a -60 dBm**: Muito bom
- **-60 a -70 dBm**: Bom
- **-70 a -80 dBm**: Aceitável
- **-80 a -90 dBm**: Fraco
- **Abaixo de -90 dBm**: Muito fraco

### Fenômenos Observados
1. **Variações normais**: Flutuações de 5-10 dBm devido a interferências
2. **Efeito Faraday**: Bloqueio quase completo em estruturas metálicas


