package main

import (
    "fmt"
    "time"
    "net/http"
    "strings"
    "io/ioutil"
)

func main() {
    for i :=0; i < 200; i++ {
        go pipe()
    }
    time.Sleep(time.Second * 2)
}

func pipe() {
    client := &http.Client{}
    req, err := http.NewRequest("GET", "http://virusdootalab.meilishuo.com/order/order_pipe", strings.NewReader("name=cjb"))
    if err != nil {
        fmt.Printf("Error get error %s\n", err)
        return
    }
    req.Header.Add("Meilishuo", "uid:4651150;ip:192.168.1.1")
    resp, err := client.Do(req)
    defer resp.Body.Close()
    body, err := ioutil.ReadAll(resp.Body)
    if err != nil {
        // handle error
        fmt.Printf("read get error %s\n", err)
        return
    }
    fmt.Println(string(body))
}
