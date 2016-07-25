{-
 fichero: Test1.hs

 compilar: $ ghc --make Test1.hs -o Test1
-}
module Main where


import System.Exit(exitSuccess)

main :: IO ()
main = do
  -- Lee una linea que contiene un único numero
  s <- getLine
  -- La siguiente linea lo convierte a un entero
  -- Si se cambia el tipo puede ser convertido a un tipo diferente
  let is = (read s)::Int
  -- Lee la siguiente linea 
  t <- getLine
  -- Convierte a un entero no es necesario por que el sistema
  -- de tipos (inferencia lo convierte a otro tipo)
  let it = read t
  let res = is + it
  putStrLn $ show res
  exitSuccess
