{-# LANGUAGE OverloadedStrings #-}

import qualified Data.Text as T

reverseWords str = T.reverse(T.intercalate " " (map T.reverse (T.splitOn " " str)))

main = print $ reverseWords "I love programming with Haskell"
