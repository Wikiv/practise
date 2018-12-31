if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
imap <S-Tab> <Plug>SuperTabBackward
inoremap <silent> <C-Tab> =UltiSnips#ListSnippets()
snoremap <silent>  c
xnoremap <silent> 	 :call UltiSnips#SaveLastVisualSelection()gvs
snoremap <silent> 	 :call UltiSnips#ExpandSnippet()
snoremap  "_c
nmap gx <Plug>NetrwBrowseX
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
snoremap <silent> <Del> c
snoremap <silent> <BS> c
snoremap <silent> <C-Tab> :call UltiSnips#ListSnippets()
inoremap <silent> 	 =UltiSnips#ExpandSnippet()
let &cpo=s:cpo_save
unlet s:cpo_save
set backspace=indent,eol,start
set cindent
set completeopt=menuone,longest
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=en
set makeprg=make\ -j16
set printoptions=paper:a4
set pumheight=20
set ruler
set runtimepath=~/.vim,~/.vim/bundle/vundle,~/.vim/bundle/vim-addon-mw-utils,~/.vim/bundle/tlib_vim,~/.vim/bundle/clang_complete,~/.vim/bundle/supertab,~/.vim/bundle/ultisnips,~/.vim/bundle/nerdtree,/var/lib/vim/addons,/usr/share/vim/vimfiles,/usr/share/vim/vim73,/usr/share/vim/vimfiles/after,/var/lib/vim/addons/after,~/.vim/after,~/.vim/bundle/vundle/,~/.vim/bundle/vundle/after,~/.vim/bundle/vim-addon-mw-utils/after,~/.vim/bundle/tlib_vim/after,~/.vim/bundle/clang_complete/after,~/.vim/bundle/supertab/after,~/.vim/bundle/ultisnips/after,~/.vim/bundle/nerdtree/after
set shiftwidth=4
set softtabstop=4
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set tabstop=4
" vim: set ft=vim :
